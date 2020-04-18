#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
  vector<vector<int>> adj;
  vector<int> depth, parent, cost, children;
  priority_queue<pair<int, int>> pq;

  void dfs(int u) {
    for (int v : adj[u]) {
      if (depth[v] == -1) {
        depth[v] = depth[u] + 1;
        parent[v] = u;
        children[u]++;
        dfs(v);
      }
    }
    if (adj[u].size() == 1 && adj[u][0] == parent[u]) {
      // is leaf
      pq.push({depth[u], u});
    }
  }

public:
  void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    adj.assign(n + 1, {});
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
    }
    depth.assign(n + 1, -1);
    parent.assign(n + 1, 0);
    cost.assign(n + 1, 0);
    children.assign(n + 1, 0);
    depth[1] = 0;
    dfs(1);
    ll ans = 0;
    int chosen = 0;
    while (chosen < k) {
      auto [value, u] = pq.top();
      pq.pop();
      chosen++;
      ans += value;
      if (parent[u] != 0) {
        cost[parent[u]] += cost[u] + 1;
        children[parent[u]]--;
        if (children[parent[u]] == 0)
          pq.push({depth[parent[u]] - cost[parent[u]], parent[u]});
      }
    }
    printf("%lld", ans);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}