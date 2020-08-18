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
  ll prefix = 0, suffix = 0, hi = 0, sum = 0;
  bool lazy = false;
} s[MAXN << 2];

Node merge(Node l, Node r) {
  Node m;
  m.l = l.l, m.r = r.r;
  m.sum = l.sum + r.sum;
  m.hi = max(l.suffix + r.prefix, max(l.hi, r.hi));
  m.prefix = max(l.prefix, l.sum + r.prefix);
  m.suffix = max(r.suffix, l.suffix + r.sum);
  return m;
}

void calc(int idx) { s[idx] = merge(s[lson], s[rson]); }

void build(int idx, int l, int r) {
  s[idx].l = l, s[idx].r = r;
  if (l == r)
    return;
  int mid = (l + r) >> 1;
  build(lson, l, mid);
  build(rson, mid + 1, r);
}

void update(int idx, int x) {
  s[idx].sum = (ll)x * (s[idx].r - s[idx].l + 1);
  s[idx].x = x;
  s[idx].hi = s[idx].prefix = s[idx].suffix = s[idx].sum > 0 ? s[idx].sum : 0;
  s[idx].lazy = true;
}

void pushdown(int idx) {
  if (s[idx].lazy)
    for (int i = lson; i <= rson; ++i)
      update(i, s[idx].x);
  s[idx].lazy = false;
}

void update(int idx, int l, int r, int x) {
  if (s[idx].l >= l && s[idx].r <= r) {
    update(idx, x);
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

Node query(int idx, int l, int r) {
  if (s[idx].l >= l && s[idx].r <= r)
    return s[idx];
  pushdown(idx);
  int mid = (s[idx].l + s[idx].r) >> 1;
  Node ans;
  if (mid >= l)
    ans = merge(ans, query(lson, l, r));
  if (mid + 1 <= r)
    ans = merge(ans, query(rson, l, r));
  return ans;
}

int main() {
  cin >> n >> m;
  build(1, 1, n);
  for (int i = 0; i < m; ++i) {
    int l, r, v;
    cin >> l >> r >> v;
    update(1, l + 1, r, v);
    cout << query(1, 1, n).hi << endl;
  }
}