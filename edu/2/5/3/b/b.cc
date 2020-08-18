#include <climits>
#include <iostream>
#define MAXN 100005
#define lson (idx << 1)
#define rson (idx << 1 | 1)

using namespace std;
typedef long long ll;
int n, m;
struct Node {
  int l, r, one = 0;
  bool lazy = false;
} s[MAXN << 2];

void calc(int idx) { s[idx].one = s[lson].one + s[rson].one; }

void build(int idx, int l, int r) {
  s[idx].l = l, s[idx].r = r;
  if (l == r)
    return;
  int mid = (l + r) >> 1;
  build(lson, l, mid);
  build(rson, mid + 1, r);
}

void update(int idx) {
  s[idx].one = s[idx].r - s[idx].l + 1 - s[idx].one;
  s[idx].lazy = !s[idx].lazy;
}

void pushdown(int idx) {
  if (s[idx].lazy)
    for (int i = lson; i <= rson; ++i)
      update(i);
  s[idx].lazy = false;
}

void update(int idx, int l, int r) {
  if (s[idx].l >= l && s[idx].r <= r) {
    update(idx);
    return;
  }
  pushdown(idx);
  int mid = (s[idx].l + s[idx].r) >> 1;
  if (mid >= l)
    update(lson, l, r);
  if (mid + 1 <= r)
    update(rson, l, r);
  calc(idx);
}

int query(int idx, int k) {
  if (s[idx].l == s[idx].r)
    return s[idx].l;
  pushdown(idx);
  int left = s[lson].one;
  if (left >= k)
    return query(lson, k);
  return query(rson, k - left);
}

int main() {
  cin >> n >> m;
  build(1, 1, n);
  for (int i = 0; i < m; ++i) {
    int t, l, r, k;
    cin >> t;
    if (t == 1) {
      cin >> l >> r;
      update(1, l + 1, r);
    } else {
      cin >> k;
      cout << query(1, k + 1) - 1 << endl;
    }
  }
}