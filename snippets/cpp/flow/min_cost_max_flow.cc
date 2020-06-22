#include <iostream>
#include <queue>
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
struct Edge {
  int u, v, c, w;
  Edge(int u, int v, int c, int w) : u(u), v(v), c(c), w(w) {}
};
class Graph {
  int n, s, t;
  vector<int> flow, dist, pre, last;
  vector<bool> vis;
  vector<Edge> edges;
  vector<vector<int>> adj;

public:
  Graph(int n, int s, int t) : n(n), s(s), t(t) {
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
    q.push(s);
    vis[s] = true;
    dist[s] = 0;
    pre[t] = -1;

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

    return pre[t] != -1;
  }

  pair<int, int> min_cost_max_flow() {
    int mincost = 0;
    int maxflow = 0;
    while (spfa()) {
      int now = t;
      mincost += flow[t] * dist[t];
      while (now != s) {
        edges[last[now]].c -= flow[t];
        edges[last[now] ^ 1].c += flow[t];
        now = pre[now];
      }
      maxflow += flow[t];
    }
    return {maxflow, mincost};
  }
};
int main() {
  int n, m, s, t;
  read(n), read(m), read(s), read(t);
  Graph g(n + 1, s, t);
  for (int i = 0; i < m; ++i) {
    int u, v, c, w;
    read(u), read(v), read(c), read(w);
    g.add_edge(u, v, c, w);
  }
  auto [maxflow, mincost] = g.min_cost_max_flow();
  printf("%d %d", maxflow, mincost);
}