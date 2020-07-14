#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>

#define lson(idx) ((idx) << 1)
#define rson(idx) ((idx) << 1 | 1)
#define MAXN 100005

template <typename T> void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-')
      sig = -1;
  for (; isdigit(c); c = getchar())
    x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

using namespace std;
typedef long long ll;
int n, m;
vector<int> a;

struct Node {
  int hi = 0, lo = INT_MAX, cnt = 0;
  bool lazy = false;
} s[MAXN * 4]{};

Node combine(Node l, Node r) {
  Node ans;
  ans.hi = max(l.hi, r.hi);
  ans.lo = min(l.lo, r.lo);
  ans.cnt = l.cnt + r.cnt;
  return ans;
}

void calc(int idx) {
  int l = lson(idx);
  int r = rson(idx);
  s[idx] = combine(s[l], s[r]);
}

void push_down(int idx) {
  if (!s[idx].lazy)
    return;
  for (int i = lson(idx); i <= rson(idx); ++i)
    s[i] = Node{0, INT_MAX, 0, true};
  s[idx].lazy = false;
}

void update(int idx, int pos, int v, int cl, int cr) {
  if (cl == pos && cr == pos) {
    s[idx] = Node{v, v, 1, false};
  } else {
    int mid = (cl + cr) >> 1;
    push_down(idx);
    if (pos <= mid)
      update(lson(idx), pos, v, cl, mid);
    else
      update(rson(idx), pos, v, mid + 1, cr);
    calc(idx);
  }
}

int query(int idx, int l, int r, int k, int cl, int cr) {
  if (cl >= l && cr <= r) {
    if (s[idx].hi <= k) {
      s[idx].hi = 0;
      s[idx].lo = INT_MAX;
      s[idx].lazy = true;
      int ret = s[idx].cnt;
      s[idx].cnt = 0;
      return ret;
    }
    if (s[idx].lo > k)
      return 0;
  }
  int ans = 0;
  int mid = (cl + cr) >> 1;
  push_down(idx);
  if (l <= mid)
    ans += query(lson(idx), l, r, k, cl, mid);
  if (mid < r)
    ans += query(rson(idx), l, r, k, mid + 1, cr);
  calc(idx);
  return ans;
}

int main() {
  read(n), read(m);
  string output;
  for (int i = 0; i < m; ++i) {
    int op, v1, v2;
    read(op), read(v1), read(v2);
    if (op == 1) {
      update(1, v1 + 1, v2, 1, n);
    } else {
      int p;
      read(p);
      output += to_string(query(1, v1 + 1, v2, p, 1, n)) + "\n";
    }
  }
  printf("%s", output.c_str());
}