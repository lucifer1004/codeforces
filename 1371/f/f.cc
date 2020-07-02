#include <cstdio>
#include <iostream>

#define MAXN 500005
#define lson (idx << 1)
#define rson (idx << 1 | 1)

using namespace std;

inline int max(int a, int b, int c) { return max(a, max(b, c)); }

struct Node {
  int l = 0, r = 0, ll = 0, lr = 0, rl = 0, rr = 0, hi = 0, lhi = 0, rhi = 0,
      nhi = 0, nlhi = 0, nrhi = 0;
  bool mark = false;
} s[MAXN * 4];

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

Node combine(Node &l, Node &r) {
  Node ans;
  ans.l = l.l, ans.r = r.r;
  ans.ll = l.ll;
  if (l.ll == l.r - l.l + 1)
    ans.ll += r.ll;

  ans.lr = l.lr;
  if (l.lr == l.r - l.l + 1)
    ans.lr += r.lr;

  ans.rl = r.rl;
  if (r.rl == r.r - r.l + 1)
    ans.rl += l.rl;

  ans.rr = r.rr;
  if (r.rr == r.r - r.l + 1)
    ans.rr += l.rr;

  int lhi = l.lhi;
  if (lhi == l.r - l.l + 1)
    lhi += r.ll;
  if (lhi == 0 && l.lr == l.r - l.l + 1) {
    if (r.ll > 0)
      lhi = l.lr + r.ll;
    if (r.lhi > 0)
      lhi = l.lr + r.lhi;
  }
  ans.lhi = lhi;

  int rhi = r.rhi;
  if (rhi == r.r - r.l + 1)
    rhi += l.rr;
  if (rhi == 0 && r.rl == r.r - r.l + 1) {
    if (l.rr > 0)
      rhi = r.rl + l.rr;
    if (l.rhi > 0)
      rhi = r.rl + l.rhi;
  }
  ans.rhi = rhi;

  int mlr = l.rhi > 0 ? l.rhi + r.ll : 0;
  int mrl = r.lhi > 0 ? r.lhi + l.rr : 0;
  int m = l.rr > 0 && r.ll > 0 ? l.rr + r.ll : 0;

  ans.hi = max(max(ans.lhi, ans.rhi), max(mlr, mrl, m), max(l.hi, r.hi));

  int nlhi = l.nlhi;
  if (nlhi == l.r - l.l + 1)
    nlhi += r.lr;
  if (nlhi == 0 && l.ll == l.r - l.l + 1) {
    if (r.lr > 0)
      nlhi = l.ll + r.lr;
    if (r.nlhi > 0)
      nlhi = l.ll + r.nlhi;
  }
  ans.nlhi = nlhi;

  int nrhi = r.nrhi;
  if (nrhi == r.r - r.l + 1)
    nrhi += l.rl;
  if (nrhi == 0 && r.rr == r.r - r.l + 1) {
    if (l.rl > 0)
      nrhi = r.rr + l.rl;
    if (l.nrhi > 0)
      nrhi = r.rr + l.nrhi;
  }
  ans.nrhi = nrhi;

  int nmlr = l.nrhi > 0 ? l.nrhi + r.lr : 0;
  int nmrl = r.nlhi > 0 ? r.nlhi + l.rl : 0;
  int nm = l.rl > 0 && r.lr > 0 ? l.rl + r.lr : 0;

  ans.nhi =
      max(max(ans.nlhi, ans.nrhi), max(nmlr, nmrl, nm), max(l.nhi, r.nhi));

  return ans;
}

void calc(int idx) { s[idx] = combine(s[lson], s[rson]); }

void flip(Node &raw);

void flip(int idx, int l, int r);

void push_down(int idx) {
  if (!s[idx].mark)
    return;
  for (int i = lson; i <= rson; ++i)
    flip(s[i]);
  s[idx].mark = false;
}

void build(int idx, int l, int r, string &ss) {
  s[idx].l = l, s[idx].r = r;
  if (l == r) {
    if (ss[l - 1] == '<') {
      s[idx].ll = 1, s[idx].lr = 0, s[idx].rl = 1, s[idx].rr = 0;
    } else {
      s[idx].ll = 0, s[idx].lr = 1, s[idx].rl = 0, s[idx].rr = 1;
    }
    return;
  }
  int mid = (l + r) >> 1;
  build(lson, l, mid, ss);
  build(rson, mid + 1, r, ss);
  calc(idx);
}

void flip(Node &raw) {
  raw.mark = !raw.mark;
  swap(raw.lr, raw.ll);
  swap(raw.rl, raw.rr);
  swap(raw.lhi, raw.nlhi);
  swap(raw.rhi, raw.nrhi);
  swap(raw.hi, raw.nhi);
}

void flip(int idx, int l, int r) {
  if (s[idx].l >= l && s[idx].r <= r) {
    flip(s[idx]);
    return;
  }
  push_down(idx);
  int mid = (s[idx].l + s[idx].r) >> 1;
  if (l <= mid)
    flip(lson, l, r);
  if (mid < r)
    flip(rson, l, r);
  calc(idx);
}

Node query(int idx, int l, int r) {
  if (s[idx].l >= l && s[idx].r <= r)
    return s[idx];
  push_down(idx);
  Node ans;
  int mid = (s[idx].l + s[idx].r) >> 1;
  if (l <= mid)
    ans = query(lson, l, r);
  if (mid < r) {
    Node right = query(rson, l, r);
    if (ans.l == 0)
      ans = right;
    else
      ans = combine(ans, right);
  }
  return ans;
}

class Solution {
public:
  void solve() {
    int n, q;
    read(n), read(q);
    string ss;
    cin >> ss;
    build(1, 1, n, ss);
    for (int i = 0; i < q; ++i) {
      int l, r;
      read(l), read(r);
      flip(1, l, r);
      Node q = query(1, l, r);
      int ans = max(q.hi, max(q.ll, q.rr));
      cout << ans << endl;
    }
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}