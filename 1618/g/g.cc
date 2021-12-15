#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

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

inline int lowbit(int x) { return x & (-x); }

struct Node {
  int r, size, parent, owned;
  ll sum;
};

class Solution {
  vector<int> crit;
  vector<ll> lookup, pre;
  vector<Node> nodes;

  int root(int i) {
    return nodes[i].parent == i ? i : nodes[i].parent = root(nodes[i].parent);
  }

  ll merge(int i, int j) {
    int ri = root(i), rj = root(j);
    if (ri != rj) {
      ll raw = nodes[ri].sum + nodes[rj].sum;
      if (nodes[ri].size < nodes[rj].size)
        swap(ri, rj);
      nodes[rj].parent = ri;
      nodes[ri].size += nodes[rj].size;
      nodes[ri].owned += nodes[rj].owned;
      nodes[ri].r = max(nodes[ri].r, nodes[rj].r);
      nodes[ri].sum =
          pre[nodes[ri].r + 1] - pre[nodes[ri].r + 1 - nodes[ri].owned];

      return nodes[ri].sum - raw;
    }

    return 0;
  }

public:
  void solve() {
    int n, m, q;
    ll ans = 0;
    read(n), read(m), read(q);
    vector<pair<int, bool>> items;
    for (int i = 0; i < n; ++i) {
      int ai;
      read(ai);
      items.emplace_back(ai, true);
      ans += ai;
    }
    for (int i = 0; i < m; ++i) {
      int bi;
      read(bi);
      items.emplace_back(bi, false);
    }

    sort(items.begin(), items.end());
    pre.resize(n + m + 1);
    for (int i = 0; i < n + m; ++i)
      pre[i + 1] = pre[i] + items[i].first;

    nodes.resize(n + m);
    for (int i = 0; i < n + m; ++i) {
      nodes[i].r = nodes[i].parent = i;
      nodes[i].size = 1;
      nodes[i].owned = items[i].second;
      nodes[i].sum = items[i].second ? items[i].first : 0;
    }

    map<int, vector<int>> delta;
    for (int i = 0; i + 1 < n + m; ++i)
      delta[items[i + 1].first - items[i].first].emplace_back(i);

    if (!delta.count(0)) {
      crit.emplace_back(0);
      lookup.emplace_back(ans);
    };

    for (auto &[di, vi] : delta) {
      crit.emplace_back(di);
      for (int i : vi)
        ans += merge(i, i + 1);
      lookup.emplace_back(ans);
    }

    for (int i = 0; i < q; ++i) {
      int k;
      read(k);
      printf(
          "%lld\n",
          lookup[upper_bound(crit.begin(), crit.end(), k) - crit.begin() - 1]);
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}