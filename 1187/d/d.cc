#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
#define INF 0x3f3f3f3f

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
  int data = INF, l = 0, r = 0;

  void combine(SegmentTreeNode other) { data = min(data, other.data); }

  inline void reset() { data = INF; }
};

class SegmentTree {
  int n;
  vector<SegmentTreeNode> nodes;

  void calc(int idx) {
    nodes[idx].reset();
    nodes[idx].combine(nodes[idx << 1]);
    nodes[idx].combine(nodes[idx << 1 | 1]);
  }

  void build(int idx, int l, int r, vector<int> &a) {
    nodes[idx].l = l, nodes[idx].r = r;
    if (l == r)
      nodes[idx].data = a[l];
    else {
      int mid = (l + r) >> 1;
      build(idx << 1, l, mid, a);
      build(idx << 1 | 1, mid + 1, r, a);
      calc(idx);
    }
  }

public:
  explicit SegmentTree(int n) {
    this->n = n;
    nodes = vector<SegmentTreeNode>((n + 1) << 2);
  }

  void init(vector<int> &a) { build(1, 1, n, a); }

  void update(int idx, int pos, int x) {
    if (nodes[idx].l == pos && nodes[idx].r == pos) {
      nodes[idx].data = x;
      return;
    }
    int mid = (nodes[idx].l + nodes[idx].r) >> 1;
    if (pos <= mid)
      update(idx << 1, pos, x);
    else
      update(idx << 1 | 1, pos, x);
    calc(idx);
  }

  SegmentTreeNode query(int idx, int l, int r) {
    if (l <= nodes[idx].l && r >= nodes[idx].r)
      return nodes[idx];
    SegmentTreeNode ans;
    int mid = (nodes[idx].l + nodes[idx].r) >> 1;
    if (l <= mid)
      ans.combine(query(idx << 1, l, r));
    if (r > mid)
      ans.combine(query(idx << 1 | 1, l, r));
    return ans;
  }
};

class Solution {
public:
  void solve() {
    int n;
    read(n);
    vector<int> a(n), b(n);
    vector<stack<int>> s(n + 1);
    for (int i = 0; i < n; ++i)
      read(a[i]);
    for (int i = n - 1; i >= 0; --i)
      s[a[i]].push(i);
    for (int i = 0; i < n; ++i)
      read(b[i]);
    vector<int> c(n + 1, INF);
    for (int i = 1; i <= n; ++i) {
      if (!s[i].empty())
        c[i] = s[i].top();
    }
    SegmentTree st(n);
    st.init(c);
    for (int i = 0; i < n; ++i) {
      if (s[b[i]].empty() || st.query(1, 1, b[i] - 1).data < s[b[i]].top()) {
        printf("NO\n");
        return;
      }
      int nxt = s[b[i]].top();
      s[b[i]].pop();
      st.update(1, b[i], s[b[i]].empty() ? INF : s[b[i]].top());
    }
    printf("YES\n");
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  read(t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}