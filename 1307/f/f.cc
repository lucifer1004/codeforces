#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#define MAX_LEVEL 20

using namespace std;

class UnionFind {
  int n;
  vector<int> parent, size;

public:
  UnionFind(int n) {
    this->n = n;
    parent = vector<int>(n);
    size = vector<int>(n, 1);
    for (int i = 0; i < n; ++i)
      parent[i] = i;
  }

  int find(int idx) {
    if (parent[idx] == idx)
      return idx;
    return parent[idx] = find(parent[idx]);
  }

  void connect(int a, int b) {
    int fa = find(a), fb = find(b);
    if (fa != fb) {
      if (size[fa] > size[fb]) {
        parent[fb] = fa;
        size[fa] += size[fb];
      } else {
        parent[fa] = fb;
        size[fb] += size[fa];
      }
    }
  }

  bool is_connected(int a, int b) { return find(a) == find(b); }
};

class Tree {
  int n, limit;
  vector<int> dist, depth;
  vector<vector<int>> adj, f;
  UnionFind uf = UnionFind(0);

  void dfs(int u, int parent) {
    depth[u] = depth[parent] + 1;
    f[u][0] = parent;
    for (int i = 1; i <= MAX_LEVEL; ++i) {
      f[u][i] = f[f[u][i - 1]][i - 1];
      if (f[u][i] == 0)
        break;
    }
    for (int v : adj[u])
      if (v != parent)
        dfs(v, u);
  }

  int la(int u, int delta) {
    for (int i = MAX_LEVEL; i >= 0; --i) {
      if (delta & (1 << i))
        u = f[u][i];
    }
    return u;
  }

  int lca(int u, int v) {
    if (depth[u] < depth[v])
      swap(u, v);
    u = la(u, depth[u] - depth[v]);
    for (int i = MAX_LEVEL; i >= 0; --i)
      if (f[u][i] != f[v][i]) {
        u = f[u][i];
        v = f[v][i];
      }
    return u == v ? u : f[u][0];
  }

  int shortest(int u, int v) {
    int w = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[w];
  }

  int walk(int u, int v, int step) {
    int w = lca(u, v);
    int left = depth[u] - depth[w], right = depth[v] - depth[w];
    if (step > left)
      return la(v, left + right - step);
    else
      return la(u, step);
  }

public:
  Tree(int n) {
    this->n = n;
    adj = vector<vector<int>>(n + 1);
    f = vector<vector<int>>(n + 1, vector<int>(MAX_LEVEL + 1));
    depth = vector<int>(n + 1, -1);
    dist = vector<int>(n + 1, -1);
    uf = UnionFind(n + 1);
  }

  void add_edge(int u, int v) {
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  void init(int limit, vector<int> &stops) {
    this->limit = limit;
    dfs(1, 0);
    queue<int> q;
    for (int stop : stops) {
      q.push(stop);
      dist[stop] = 0;
    }
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (dist[u] == limit)
        break;
      for (int v : adj[u]) {
        uf.connect(u, v);
        if (dist[v] == -1) {
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }
  }

  bool query(int u, int v) {
    int uv = shortest(u, v);
    if (uv <= 2 * limit)
      return true;
    else
      return uf.is_connected(walk(u, v, limit), walk(v, u, limit));
  }
};

class Solution {
public:
  void solve() {
    int n, k, r;
    scanf("%d%d%d", &n, &k, &r);
    Tree tree(n * 2);
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      tree.add_edge(u, n + i);
      tree.add_edge(n + i, v);
    }
    vector<int> stops(r);
    for (int i = 0; i < r; ++i)
      scanf("%d", &stops[i]);
    tree.init(k, stops);
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      printf(tree.query(u, v) ? "YES\n" : "NO\n");
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}