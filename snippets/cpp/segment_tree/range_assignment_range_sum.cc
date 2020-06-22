#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

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
  int data = 0, lazy = 0, timestamp = 0, l = 0, r = 0;

  void combine(SegmentTreeNode other) {
    data += other.data;
    timestamp = max(timestamp, other.timestamp);
  }

  inline void reset() { data = 0; }
};

class SegmentTree {
  int n;
  vector<SegmentTreeNode> nodes;

  void calc(int idx) {
    nodes[idx].reset();
    nodes[idx].combine(nodes[idx << 1]);
    nodes[idx].combine(nodes[idx << 1 | 1]);
  }

  void build(int idx, int l, int r) {
    nodes[idx].l = l, nodes[idx].r = r;
    if (l == r)
      nodes[idx].data = 1;
    else {
      int mid = (l + r) >> 1;
      build(idx << 1, l, mid);
      build(idx << 1 | 1, mid + 1, r);
      calc(idx);
    }
  }

  void push_down(int idx) {
    // In this problem, assignments are within [1..3], so we can
    // safely reset lazy to 0 after pushing down.
    if (nodes[idx].lazy == 0)
      return;
    for (int i = idx << 1; i <= (idx << 1 | 1); ++i) {
      if (nodes[i].timestamp >= nodes[idx].timestamp)
        continue;
      nodes[i].data = nodes[idx].lazy * (nodes[i].r - nodes[i].l + 1);
      nodes[i].lazy = nodes[idx].lazy;
      nodes[i].timestamp = nodes[idx].timestamp;
    }
    nodes[idx].lazy = 0;
  }

public:
  explicit SegmentTree(int n) {
    this->n = n;
    nodes = vector<SegmentTreeNode>((n + 1) << 2);
  }

  void init() { build(1, 1, n); }

  void update(int idx, int l, int r, int x, int timestamp) {
    if (l <= nodes[idx].l && r >= nodes[idx].r) {
      nodes[idx].data = x * (nodes[idx].r - nodes[idx].l + 1);
      nodes[idx].lazy = x;
      nodes[idx].timestamp = timestamp;
    } else {
      push_down(idx);
      int mid = (nodes[idx].l + nodes[idx].r) >> 1;
      if (l <= mid)
        update(idx << 1, l, r, x, timestamp);
      if (r > mid)
        update(idx << 1 | 1, l, r, x, timestamp);
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
  int t;
  read(t);
  for (int k = 1; k <= t; ++k) {
    int n, m;
    read(n), read(m);
    SegmentTree st(n);
    st.init();
    for (int i = 1; i <= m; ++i) {
      int l, r, x;
      read(l), read(r), read(x);
      st.update(1, l, r, x, i);
    }
    printf("Case %d: The total value of the hook is %d.\n", k,
           st.query(1, 1, n).data);
  }
}