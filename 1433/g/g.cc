#include <iostream>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f

using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<int, int>>> adj(n);
  vector<vector<int>> edges, routes;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
    edges.push_back({u, v});
  }
  for (int i = 0; i < k; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    routes.push_back({u, v});
  }
  vector<vector<int>> d(n, vector<int>(n, INF));
  for (int i = 0; i < n; ++i) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, i);
    d[i][i] = 0;
    vector<bool> vis(n);
    while (!pq.empty()) {
      auto [dis, u] = pq.top();
      pq.pop();
      if (vis[u])
        continue;
      vis[u] = true;
      for (auto [v, w] : adj[u]) {
        if (dis + w < d[i][v]) {
          d[i][v] = dis + w;
          pq.emplace(dis + w, v);
        }
      }
    }
  }
  int ans = INF;
  for (auto &e : edges) {
    int u = e[0], v = e[1];
    int sum = 0;
    for (auto &r : routes) {
      int p = r[0], q = r[1];
      int dis = min(d[p][q], min(d[p][u] + d[v][q], d[p][v] + d[u][q]));
      sum += dis;
    }
    ans = min(ans, sum);
  }
  cout << ans;
}