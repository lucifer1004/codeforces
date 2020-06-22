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

struct SegmentTreeNode {
  ll data = 0, lazy = 0;
  int l = 0, r = 0;
  void combine(SegmentTreeNode other) { data += other.data; }

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
    if (nodes[idx].lazy == 0)
      return;
    for (int i = idx << 1; i <= (idx << 1 | 1); ++i) {
      nodes[i].data += nodes[idx].lazy * (nodes[i].r - nodes[i].l + 1);
      nodes[i].lazy += nodes[idx].lazy;
    }
    nodes[idx].lazy = 0;
  }

public:
  explicit SegmentTree(int n) {
    this->n = n;
    nodes = vector<SegmentTreeNode>((n + 1) << 2);
  }

  void init() {
    a = vector<ll>(n + 1);
    for (int i = 1; i <= n; ++i)
      read(a[i]);
    build(1, 1, n);
  }

  void update(int idx, int l, int r, int delta) {
    if (l <= nodes[idx].l && r >= nodes[idx].r) {
      nodes[idx].data += (ll)delta * (nodes[idx].r - nodes[idx].l + 1);
      nodes[idx].lazy += delta;
    } else {
      push_down(idx);
      int mid = (nodes[idx].l + nodes[idx].r) >> 1;
      if (l <= mid)
        update(idx << 1, l, r, delta);
      if (r > mid)
        update(idx << 1 | 1, l, r, delta);
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
  read(n), read(m);
  SegmentTree st(n);
  st.init();
  for (int i = 0; i < m; ++i) {
    int op, l, r, x;
    read(op), read(l), read(r);
    if (op == 1) {
      read(x);
      st.update(1, l, r, x);
    } else {
      printf("%lld\n", st.query(1, l, r).data);
    }
  }
}