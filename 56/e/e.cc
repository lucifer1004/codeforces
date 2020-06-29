#include <algorithm>
#include <iostream>
#include <vector>
#define MAXN 100005

using namespace std;
struct {
  int data = 0, l = 0, r = 0;
} s[MAXN * 4];
struct Domino {
  int pos, height, idx;
  bool operator<(const Domino &other) const { return pos < other.pos; }
};
void calc(int idx) {
  s[idx].data = max(s[idx << 1].data, s[idx << 1 | 1].data);
}
void build(int idx, int l, int r) {
  s[idx].l = l, s[idx].r = r;
  if (l == r) {
    s[idx].data = l;
    return;
  }
  int mid = (l + r) >> 1;
  build(idx << 1, l, mid);
  build(idx << 1 | 1, mid + 1, r);
  calc(idx);
}
void update(int idx, int pos, int x) {
  if (s[idx].l == pos && s[idx].r == pos) {
    s[idx].data = x;
    while (idx > 1) {
      idx >>= 1;
      calc(idx);
    }
    return;
  }
  int mid = (s[idx].l + s[idx].r) >> 1;
  if (pos <= mid)
    update(idx << 1, pos, x);
  else
    update(idx << 1 | 1, pos, x);
}
int query(int idx, int l, int r) {
  if (s[idx].l >= l && s[idx].r <= r)
    return s[idx].data;
  int ans = 0;
  int mid = (s[idx].l + s[idx].r) >> 1;
  if (l <= mid)
    ans = max(ans, query(idx << 1, l, r));
  if (mid < r)
    ans = max(ans, query(idx << 1 | 1, l, r));
  return ans;
}
int main() {
  int n;
  cin >> n;
  vector<Domino> dominoes;
  for (int i = 0; i < n; ++i) {
    int x, h;
    cin >> x >> h;
    dominoes.emplace_back(Domino{x, h, i});
  }
  sort(dominoes.begin(), dominoes.end());
  vector<int> pos(n);
  for (int i = 0; i < n; ++i)
    pos[i] = dominoes[i].pos;
  build(1, 1, n);
  vector<int> ans(n);
  for (int i = n; i >= 1; --i) {
    Domino &d = dominoes[i - 1];
    int r =
        upper_bound(pos.begin(), pos.end(), d.pos + d.height - 1) - pos.begin();
    int new_val = query(1, i, r);
    ans[d.idx] = new_val - i + 1;
    update(1, i, new_val);
  }
  for (int i : ans)
    cout << i << " ";
}