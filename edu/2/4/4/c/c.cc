#include <cstdio>
#include <iostream>
#include <vector>

#define lson(idx) ((idx) << 1)
#define rson(idx) ((idx) << 1 | 1)
#define MAXN 100005

inline int lowbit(int x) { return x & (-x); }
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
  ll p = 0;
  int a[41]{};
  int cnt[41]{};
  Node() {}
  int query(int idx) {
    int ans = 0;
    for (; idx > 0; idx -= lowbit(idx))
      ans += a[idx];
    return ans;
  }

  void update(int idx, int delta) {
    for (; idx <= 40; idx += lowbit(idx))
      a[idx] += delta;
  }
} s[MAXN * 4];

Node combine(Node l, Node r) {
  Node ans;
  ans.p = l.p + r.p;
  for (int i = 1; i <= 40; ++i) {
    ans.p += (ll)r.cnt[i] * l.query(40 - i);
    ans.a[i] = l.a[i] + r.a[i];
    ans.cnt[i] = l.cnt[i] + r.cnt[i];
  }
  return ans;
}

void calc(int idx) {
  int l = lson(idx);
  int r = rson(idx);
  s[idx] = combine(s[l], s[r]);
}

void build(int idx, int l, int r) {
  if (l == r) {
    s[idx].update(41 - a[l], 1);
    s[idx].cnt[a[l]] = 1;
  } else {
    int mid = (l + r) >> 1;
    build(lson(idx), l, mid);
    build(rson(idx), mid + 1, r);
    calc(idx);
  }
}

void update(int idx, int pos, int v, int cl, int cr) {
  if (cl == pos && cr == pos) {
    s[idx].update(41 - a[pos], -1);
    s[idx].cnt[a[pos]]--;
    s[idx].update(41 - v, 1);
    s[idx].cnt[v]++;
    a[pos] = v;
  } else {
    int mid = (cl + cr) >> 1;
    if (pos <= mid)
      update(lson(idx), pos, v, cl, mid);
    else
      update(rson(idx), pos, v, mid + 1, cr);
    calc(idx);
  }
}

Node query(int idx, int l, int r, int cl, int cr) {
  if (cl >= l && cr <= r)
    return s[idx];
  int mid = (cl + cr) >> 1;
  Node ans;
  if (l <= mid)
    ans = combine(ans, query(lson(idx), l, r, cl, mid));
  if (mid < r)
    ans = combine(ans, query(rson(idx), l, r, mid + 1, cr));
  return ans;
}

int main() {
  read(n), read(m);
  a = vector<int>(n + 1);
  for (int i = 1; i <= n; ++i)
    read(a[i]);
  build(1, 1, n);
  string output;
  for (int i = 0; i < m; ++i) {
    int op, v1, v2;
    read(op), read(v1), read(v2);
    if (op == 1) {
      output += to_string(query(1, v1, v2, 1, n).p) + "\n";
    } else {
      update(1, v1, v2, 1, n);
    }
  }
  printf("%s", output.c_str());
}