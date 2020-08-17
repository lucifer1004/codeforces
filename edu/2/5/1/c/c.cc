#include <iostream>
#define MAXN 100005
#define lson (idx << 1)
#define rson (idx << 1 | 1)

using namespace std;
int n, m;
struct Node {
  int l, r, lo = 0, hi = 0;
} s[MAXN << 2];

void calc(int idx) {
  s[idx].lo = min(s[lson].lo, s[rson].lo);
  s[idx].hi = max(s[lson].hi, s[rson].hi);
}

void build(int idx, int l, int r) {
  s[idx].l = l, s[idx].r = r;
  if (l == r)
    return;
  int mid = (l + r) >> 1;
  build(lson, l, mid);
  build(rson, mid + 1, r);
}

void pushdown(int idx) {
  if (s[idx].lo == s[idx].hi)
    for (int i = lson; i <= rson; ++i)
      s[i].lo = s[i].hi = s[idx].lo;
}

void update(int idx, int l, int r, int x) {
  if (s[idx].l >= l && s[idx].r <= r) {
    s[idx].lo = x;
    s[idx].hi = x;
    return;
  }
  pushdown(idx);
  int mid = (s[idx].l + s[idx].r) >> 1;
  if (mid >= l)
    update(lson, l, r, x);
  if (mid + 1 <= r)
    update(rson, l, r, x);
  calc(idx);
}

int query(int idx, int pos) {
  if (s[idx].l == s[idx].r || s[idx].lo == s[idx].hi)
    return s[idx].lo;
  pushdown(idx);
  int mid = (s[idx].l + s[idx].r) >> 1;
  if (pos <= mid)
    return query(lson, pos);
  return query(rson, pos);
}

int main() {
  cin >> n >> m;
  build(1, 1, n);
  for (int i = 0; i < m; ++i) {
    int t, l, r, x, v;
    cin >> t;
    if (t == 1) {
      cin >> l >> r >> v;
      update(1, l + 1, r, v);
    } else {
      cin >> x;
      cout << query(1, x + 1) << endl;
    }
  }
}