#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long ll;

struct Edge {
  int to, w;
};

class Solution {
  int n, k;
  vector<vector<Edge>> adj;
  vector<ll> f, g;
  // f: maximum value when back edge is chosen
  // g: maximum value when back edge is not chose

  void dfs(int u, int parent) {
    priority_queue<pair<ll, int>> pq;
    for (Edge edge : adj[u]) {
      int v = edge.to, w = edge.w;
      if (v == parent)
        continue;
      dfs(v, u);
      pq.push(make_pair(f[v] + w - g[v], v));
    }

    unordered_set<int> cf, cg;
    while (!pq.empty() && cg.size() < k && pq.top().first > 0) {
      cg.insert(pq.top().second);
      if (cg.size() < k)
        cf.insert(pq.top().second);
      pq.pop();
    }
    for (Edge edge : adj[u]) {
      int v = edge.to, w = edge.w;
      if (v == parent)
        continue;
      if (cf.find(v) != cf.end())
        f[u] += f[v] + w;
      else
        f[u] += g[v];
      if (cg.find(v) != cg.end())
        g[u] += f[v] + w;
      else
        g[u] += g[v];
    }
  }

public:
  void solve() {
    scanf("%d%d", &n, &k);
    adj = vector<vector<Edge>>(n + 1);
    for (int i = 0; i < n - 1; ++i) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      adj[u].emplace_back(Edge{v, w});
      adj[v].emplace_back(Edge{u, w});
    }
    f = vector<ll>(n + 1);
    g = vector<ll>(n + 1);
    dfs(1, 0);
    printf("%lld\n", g[1]);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  scanf("%d", &t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}