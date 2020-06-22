#include <iostream>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f

using namespace std;
struct Edge {
  int u, v, c, w;
  Edge(int u, int v, int c, int w) : u(u), v(v), c(c), w(w) {}
};
class Graph {
  int n;
  vector<int> flow, dist, pre, last;
  vector<bool> vis;
  vector<Edge> edges;
  vector<vector<int>> adj;

public:
  Graph(int n) : n(n) {
    adj = vector<vector<int>>(n);
    flow.reserve(n);
    dist.reserve(n);
    pre.reserve(n);
    last.reserve(n);
    vis.reserve(n);
  }
  void add_edge(int u, int v, int c, int w) {
    int m = edges.size();
    edges.emplace_back(u, v, c, w);
    edges.emplace_back(v, u, 0, -w);
    adj[u].emplace_back(m);
    adj[v].emplace_back(m | 1);
  }

  bool spfa() {
    dist.assign(n, INF);
    flow.assign(n, INF);
    vis.assign(n, false);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    dist[0] = 0;
    pre[n - 1] = -1;

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      vis[u] = false;
      for (int e : adj[u]) {
        auto [_, v, c, w] = edges[e];
        if (c > 0 && dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
          pre[v] = u;
          last[v] = e;
          flow[v] = min(flow[u], c);
          if (!vis[v]) {
            vis[v] = true;
            q.push(v);
          }
        }
      }
    }

    return pre[n - 1] != -1;
  }

  int min_cost_max_flow() {
    int ans = 0;
    int maxflow = 0;
    while (spfa()) {
      int now = n - 1;
      ans += flow[n - 1] * dist[n - 1];
      while (now != 0) {
        edges[last[now]].c -= flow[n - 1];
        edges[last[now] ^ 1].c += flow[n - 1];
        now = pre[now];
      }
      maxflow += flow[n - 1];
    }
    return ans;
  }
};
int main() {
  int n, m, k, c, d;
  cin >> n >> m >> k >> c >> d;
  vector<int> pos(k);
  for (int i = 0; i < k; ++i)
    cin >> pos[i];
  vector<pair<int, int>> edges;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }
  // Node i in Layer k is (k - 1)n + i
  int source = 0;
  int layers = n + k + 1;
  int tot = layers * n + 2;
  int target = tot - 1;
  Graph g(tot);
  // Source to each residence
  for (int i : pos)
    g.add_edge(source, i, 1, 0);
  for (int layer = 0; layer < layers; ++layer) {
    // Each layer's endpoint to target
    g.add_edge(layer * n + 1, target, k, layer * c);
    if (layer < layers - 1) {
      // Original edges
      for (auto [u, v] : edges) {
        for (int j = 1; j <= k; ++j) {
          g.add_edge(layer * n + u, (layer + 1) * n + v, 1, d * (2 * j - 1));
          g.add_edge(layer * n + v, (layer + 1) * n + u, 1, d * (2 * j - 1));
        }
      }
      // Wait
      for (int j = 1; j <= n; ++j)
        g.add_edge(layer * n + j, (layer + 1) * n + j, k, 0);
    }
  }
  cout << g.min_cost_max_flow();
}