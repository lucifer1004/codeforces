#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int u, v, w;
  bool operator<(const Edge a) const { return w < a.w; }
};

class Solution {
  int n, m, k;
  vector<int> parent, rank;
  vector<bool> special;

  int find(int u) {
    if (parent[u] == u)
      return u;
    return parent[u] = find(parent[u]);
  }

  void connect(int u, int v) {
    int fu = find(u), fv = find(v);
    if (fu == fv)
      return;
    if (rank[fu] >= rank[fv]) {
      parent[fv] = fu;
      rank[fu] += rank[fv];
      if (special[fv])
        special[fu] = true;
    } else {
      parent[fu] = fv;
      rank[fv] += rank[fu];
      if (special[fu])
        special[fv] = true;
    }
  }

public:
  void solve() {
    scanf("%d%d%d", &n, &m, &k);
    special = vector<bool>(n + 1);
    parent = vector<int>(n + 1);
    rank = vector<int>(n + 1, 1);
    for (int i = 1; i <= n; ++i)
      parent[i] = i;
    for (int i = 0; i < k; ++i) {
      int u;
      scanf("%d", &u);
      special[u] = true;
    }
    vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      edges.emplace_back(Edge{u, v, w});
    }
    sort(edges.begin(), edges.end());
    int ans = 0, cnt = 0;
    for (auto edge : edges) {
      int u = edge.u, v = edge.v, w = edge.w;
      int fu = find(u), fv = find(v);
      if (fu == fv)
        continue;
      if (special[fu] && special[fv])
        ans = max(ans, w);
      connect(fu, fv);
      cnt++;
      if (cnt == n - 1)
        break;
    }
    for (int i = 0; i < k; ++i)
      printf("%d ", ans);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}