#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct Edge {
  int idx, to;
};

class UnionFind {
  vector<int> f, s;

public:
  UnionFind(int n) {
    f.assign(n, 0);
    s.assign(n, 1);
    for (int i = 0; i < n; ++i)
      f[i] = i;
  }

  int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }

  void connect(int u, int v) {
    int fu = find(u), fv = find(v);
    if (fu != fv) {
      if (s[fu] > s[fv]) {
        f[fv] = fu;
        s[fu] += s[fv];
      } else {
        f[fu] = fv;
        s[fv] += s[fu];
      }
    }
  }

  int size() {
    int ans = 0;
    for (int i = 0; i < f.size(); ++i)
      ans += find(i) == i;
    return ans;
  }
};

vector<vector<Edge>> adj;
vector<bool> vis;
set<int> s;
UnionFind uf = UnionFind(0);

void dfs(int u, int val) {
  vis[u] = true;
  int leaf = -1;
  for (Edge e : adj[u]) {
    int v = e.to;
    if (vis[v])
      continue;
    if (adj[v].size() == 1) {
      s.insert(val ^ 1);
      if (leaf == -1)
        leaf = e.idx;
      else
        uf.connect(leaf, e.idx);
    } else
      dfs(v, val ^ 1);
  }
}

int main() {
  int n;
  cin >> n;
  adj.assign(n + 1, {});
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(Edge{i, v});
    adj[v].emplace_back(Edge{i, u});
  }
  int root = 1;
  uf = UnionFind(n - 1);
  while (adj[root].size() <= 1)
    root++;
  vis.assign(n + 1, false);
  dfs(root, 0);
  cout << (s.size() == 1 ? 1 : 3) << " " << uf.size();
}