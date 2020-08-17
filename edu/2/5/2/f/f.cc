#include <climits>
#include <iostream>
#define MAXN 100005
#define lson (idx << 1)
#define rson (idx << 1 | 1)

using namespace std;
typedef long long ll;
int n, m;
struct Node {
  int l, r, x = 0;
  ll val = 0;
  bool lazy = false;
} s[MAXN << 2];

void calc(int idx) { s[idx].val = s[lson].val + s[rson].val; }

void build(int idx, int l, int r) {
  s[idx].l = l, s[idx].r = r;
  if (l == r)
    return;
  int mid = (l + r) >> 1;
  build(lson, l, mid);
  build(rson, mid + 1, r);
}

void pushdown(int idx) {
  if (s[idx].lazy) {
    for (int i = lson; i <= rson; ++i)
      s[i].val = (ll)s[idx].x * (s[i].r - s[i].l + 1), s[i].x = s[idx].x,
      s[i].lazy = true;
  }
  s[idx].lazy = false;
}

void update(int idx, int l, int r, int x) {
  if (s[idx].l >= l && s[idx].r <= r) {
    s[idx].val = (ll)x * (s[idx].r - s[idx].l + 1);
    s[idx].x = x;
    s[idx].lazy = true;
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
    return s[idx].val;
  pushdown(idx);
  int mid = (s[idx].l + s[idx].r) >> 1;
  ll ans = 0;
  if (mid >= l)
    ans += query(lson, l, r);
  if (mid + 1 <= r)
    ans += query(rson, l, r);
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