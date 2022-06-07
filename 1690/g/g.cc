#include <cstdio>
#include <iostream>
#include <vector>
#define MAXN 100005
#define lson (idx << 1)
#define rson (idx << 1 | 1)

using namespace std;

template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-') sig = -1;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

struct Node {
  int l, r, vl, vr, diff;
  bool lazy;
} s[MAXN << 2];

void calc(int idx) {
  s[idx].vl = s[lson].vl;
  s[idx].vr = s[rson].vr;
  s[idx].diff = s[lson].diff + s[rson].diff;
  if (s[lson].vr == s[rson].vl) s[idx].diff--;
}

void build(int idx, int l, int r, vector<int> &v) {
  s[idx].l = l, s[idx].r = r, s[idx].lazy = false;
  if (l == r) {
    s[idx].vl = s[idx].vr = v[l];
    s[idx].diff = 1;
  } else {
    int m = (l + r) >> 1;
    build(lson, l, m, v);
    build(rson, m + 1, r, v);
    calc(idx);
  }
}

void pushdown(int idx) {
  if (s[idx].lazy) {
    for (int i = lson; i <= rson; ++i) {
      s[i].vl = s[i].vr = s[idx].vl;
      s[i].diff = 1;
      s[i].lazy = true;
    }
    s[idx].lazy = false;
  }
}

int ub(int idx, int v) {
  if (s[idx].vr >= v) return s[idx].r + 1;
  if (s[idx].vl < v) return s[idx].l;
  pushdown(idx);
  if (s[lson].vr < v)
    return ub(lson, v);
  else
    return ub(rson, v);
}

int query(int idx, int p) {
  if (s[idx].l == s[idx].r) return s[idx].vl;
  pushdown(idx);
  int m = (s[idx].l + s[idx].r) >> 1;
  if (p <= m) return query(lson, p);
  return query(rson, p);
}

void update(int idx, int l, int r, int v) {
  if (s[idx].l >= l && s[idx].r <= r) {
    s[idx].vl = s[idx].vr = v;
    s[idx].diff = 1;
    s[idx].lazy = true;
  } else {
    pushdown(idx);
    int m = (s[idx].l + s[idx].r) >> 1;
    if (l <= m) update(lson, l, r, v);
    if (m + 1 <= r) update(rson, l, r, v);
    calc(idx);
  }
}

class Solution {
 public:
  void solve() {
    int n, m;
    read(n), read(m);
    vector<int> v(n + 1), w(n + 1);
    for (int i = 1; i <= n; i++) {
      read(v[i]);
      w[i] = v[i];
      if (i > 1) w[i] = min(w[i], w[i - 1]);
    }

    build(1, 1, n, w);
    for (int i = 0; i < m; ++i) {
      int k, d;
      read(k), read(d);
      int now = query(1, k);
      v[k] -= d;
      if (v[k] < now) {
        int id = ub(1, v[k]);
        update(1, k, id - 1, v[k]);
      }
      printf("%d ", s[1].diff);
    }
    printf("\n");
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  read(t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}