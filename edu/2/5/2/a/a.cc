#include <climits>
#include <iostream>
#define MAXN 100005
#define lson (idx << 1)
#define rson (idx << 1 | 1)

using namespace std;
typedef long long ll;
int n, m;
struct Node {
  int l, r;
  ll lo = 0, lazy = 0;
} s[MAXN << 2];

void calc(int idx) { s[idx].lo = min(s[lson].lo, s[rson].lo); }

void build(int idx, int l, int r) {
  s[idx].l = l, s[idx].r = r;
  if (l == r)
    return;
  int mid = (l + r) >> 1;
  build(lson, l, mid);
  build(rson, mid + 1, r);
}

void pushdown(int idx) {
  if (s[idx].lazy)
    for (int i = lson; i <= rson; ++i)
      s[i].lo += s[idx].lazy, s[i].lazy += s[idx].lazy;
  s[idx].lazy = 0;
}

void update(int idx, int l, int r, int x) {
  if (s[idx].l >= l && s[idx].r <= r) {
    s[idx].lo += x;
    s[idx].lazy += x;
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

ll query(int idx, int l, int r) {
  if (s[idx].l >= l && s[idx].r <= r)
    return s[idx].lo;
  pushdown(idx);
  int mid = (s[idx].l + s[idx].r) >> 1;
  ll ans = LLONG_MAX;
  if (mid >= l)
    ans = min(ans, query(lson, l, r));
  if (mid + 1 <= r)
    ans = min(ans, query(rson, l, r));
  return ans;
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
      cin >> l >> r;
      cout << query(1, l + 1, r) << endl;
    }
  }
}