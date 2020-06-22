#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

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

int p;

struct SegmentTreeNode {
  ll data = 0, lazy_add = 0, lazy_mul = 1;
  int l = 0, r = 0;

  void combine(SegmentTreeNode other) { data = (data + other.data) % p; }

  inline void reset() { data = 0; }
};

class SegmentTree {
  int n;
  vector<ll> a;
  vector<SegmentTreeNode> nodes;

  void calc(int idx) {
    nodes[idx].reset();
    nodes[idx].combine(nodes[idx << 1]);
    nodes[idx].combine(nodes[idx << 1 | 1]);
  }

  void build(int idx, int l, int r) {
    nodes[idx].l = l, nodes[idx].r = r;
    if (l == r)
      nodes[idx].data = a[l];
    else {
      int mid = (l + r) >> 1;
      build(idx << 1, l, mid);
      build(idx << 1 | 1, mid + 1, r);
      calc(idx);
    }
  }

  void push_down(int idx) {
    for (int i = idx << 1; i <= (idx << 1 | 1); ++i) {
      nodes[i].data = nodes[i].data * nodes[idx].lazy_mul % p;
      nodes[i].data = (nodes[i].data +
                       (nodes[i].r - nodes[i].l + 1) * nodes[idx].lazy_add) %
                      p;
      nodes[i].lazy_add =
          (nodes[i].lazy_add * nodes[idx].lazy_mul + nodes[idx].lazy_add) % p;
      nodes[i].lazy_mul = nodes[i].lazy_mul * nodes[idx].lazy_mul % p;
    }
    nodes[idx].lazy_add = 0;
    nodes[idx].lazy_mul = 1;
  }

public:
  explicit SegmentTree(int n) : n(n) {
    nodes = vector<SegmentTreeNode>((n + 1) << 2);
  }

  void init() {
    a = vector<ll>(n + 1);
    for (int i = 1; i <= n; ++i)
      read(a[i]);
    build(1, 1, n);
  }

  void mul(int idx, int l, int r, int delta) {
    if (l <= nodes[idx].l && r >= nodes[idx].r) {
      nodes[idx].data = nodes[idx].data * delta % p;
      nodes[idx].lazy_add = nodes[idx].lazy_add * delta % p;
      nodes[idx].lazy_mul = nodes[idx].lazy_mul * delta % p;
    } else {
      push_down(idx);
      int mid = (nodes[idx].l + nodes[idx].r) >> 1;
      if (l <= mid)
        mul(idx << 1, l, r, delta);
      if (r > mid)
        mul(idx << 1 | 1, l, r, delta);
      calc(idx);
    }
  }

  void add(int idx, int l, int r, int delta) {
    if (l <= nodes[idx].l && r >= nodes[idx].r) {
      nodes[idx].data =
          (nodes[idx].data + (ll)delta * (nodes[idx].r - nodes[idx].l + 1)) % p;
      nodes[idx].lazy_add = (nodes[idx].lazy_add + delta) % p;
    } else {
      push_down(idx);
      int mid = (nodes[idx].l + nodes[idx].r) >> 1;
      if (l <= mid)
        add(idx << 1, l, r, delta);
      if (r > mid)
        add(idx << 1 | 1, l, r, delta);
      calc(idx);
    }
  }

  SegmentTreeNode query(int idx, int l, int r) {
    if (l <= nodes[idx].l && r >= nodes[idx].r)
      return nodes[idx];
    push_down(idx);
    SegmentTreeNode ans;
    int mid = (nodes[idx].l + nodes[idx].r) >> 1;
    if (l <= mid)
      ans.combine(query(idx << 1, l, r));
    if (r > mid)
      ans.combine(query(idx << 1 | 1, l, r));
    return ans;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  read(n), read(m), read(p);
  SegmentTree st(n);
  st.init();
  for (int i = 0; i < m; ++i) {
    int op, l, r, x;
    read(op), read(l), read(r);
    if (op == 1) {
      read(x);
      st.mul(1, l, r, x);
    } else if (op == 2) {
      read(x);
      st.add(1, l, r, x);
    } else {
      printf("%lld\n", st.query(1, l, r).data);
    }
  }
}