#include <climits>
#include <iostream>
#include <vector>
#define MAXN 200005

using namespace std;
typedef long long ll;
struct {
  ll data = LLONG_MAX, lazy = 0;
  int l = 0, r = 0;
} s[MAXN * 4];
int a[MAXN];

void calc(int idx) {
  s[idx].data = min(s[idx << 1].data, s[idx << 1 | 1].data);
}

void push_down(int idx) {
  for (int i = idx << 1; i <= (idx << 1 | 1); ++i) {
    s[i].data += s[idx].lazy;
    s[i].lazy += s[idx].lazy;
  }
  s[idx].lazy = 0;
  calc(idx);
}

void build(int idx, int l, int r) {
  s[idx].l = l, s[idx].r = r;
  if (l == r) {
    s[idx].data = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(idx << 1, l, mid);
  build(idx << 1 | 1, mid + 1, r);
  calc(idx);
}

void update(int idx, int l, int r, int delta) {
  if (s[idx].l >= l && s[idx].r <= r) {
    s[idx].data += delta;
    s[idx].lazy += delta;
    return;
  }
  push_down(idx);
  int mid = (s[idx].l + s[idx].r) >> 1;
  if (l <= mid)
    update(idx << 1, l, r, delta);
  if (mid < r)
    update(idx << 1 | 1, l, r, delta);
  calc(idx);
}

ll query(int idx, int l, int r) {
  if (s[idx].l >= l && s[idx].r <= r)
    return s[idx].data;
  push_down(idx);
  ll ans = LLONG_MAX;
  int mid = (s[idx].l + s[idx].r) >> 1;
  if (l <= mid)
    ans = min(ans, query(idx << 1, l, r));
  if (mid < r)
    ans = min(ans, query(idx << 1 | 1, l, r));
  return ans;
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  build(1, 1, n);
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int l, r, v;
    cin >> l >> r;
    l++, r++;
    vector<pair<int, int>> seg;
    if (l <= r)
      seg.emplace_back(l, r);
    else {
      seg.emplace_back(l, n);
      seg.emplace_back(1, r);
    }
    if (getchar() == 10) {
      ll ans = LLONG_MAX;
      for (auto [l, r] : seg)
        ans = min(ans, query(1, l, r));
      cout << ans << endl;
    } else {
      cin >> v;
      for (auto [l, r] : seg)
        update(1, l, r, v);
    }
  }
}