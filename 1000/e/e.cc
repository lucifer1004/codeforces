#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

class UnionFind {
  vector<int> f;

  int find(int i) {
    if (i == f[i]) return i;
    return f[i] = find(f[i]);
  }

 public:
  UnionFind(int n) {
    f = vector<int>(n);
    for (int i = 0; i < n; ++i) f[i] = i;
  }

  void connect(int a, int b) {
    int fa = find(a);
    int fb = find(b);
    if (fa != fb) f[fb] = fa;
  }

  vector<int> get_mapping() {
    for (int i = 0; i < f.size(); ++i) find(i);
    return f;
  }
};

class Graph {
  int n, order;
  vector<int> dfn, low, parent;
  vector<bool> visited;
  vector<vector<int>> adj;
  vector<pair<int, int>> bridges, non_bridges;

  void dfs(int i) {
    low[i] = dfn[i] = order;
    visited[i] = true;
    for (int j : adj[i]) {
      if (j == parent[i]) continue;
      if (!visited[j]) {
        order++;
        parent[j] = i;
        dfs(j);
      }
      low[i] = min(low[i], low[j]);
    }
  }

  void find_bridges(int i) {
    visited[i] = true;
    for (int j : adj[i]) {
      if (visited[j]) continue;
      if (low[j] > dfn[i])
        bridges.push_back(make_pair(i, j));
      else
        non_bridges.push_back(make_pair(i, j));
      find_bridges(j);
    }
  }

  pair<int, int> longest(int i) {
    queue<pair<int, int>> q;
    vector<bool> v(n);
    int maxlen = -1, li = -1;
    q.push(make_pair(i, 0));
    v[i] = true;

    while (!q.empty()) {
      auto f = q.front();
      q.pop();
      if (f.second > maxlen) {
        maxlen = f.second;
        li = f.first;
      }

      for (int j : adj[f.first]) {
        if (!v[j]) {
          v[j] = true;
          q.push(make_pair(j, f.second + 1));
        }
      }
    }

    return make_pair(maxlen, li);
  }

 public:
  Graph(int n) {
    this->n = n;
    adj = vector<vector<int>>(n);
  }

  void add_edge(int i, int j) {
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  void solve() {
    dfn = vector<int>(n);
    low = vector<int>(n);
    parent = vector<int>(n);
    visited = vector<bool>(n);
    order = 0;
    dfs(0);
    visited = vector<bool>(n);
    find_bridges(0);

    UnionFind uf = UnionFind(n);
    for (auto p : non_bridges) {
      uf.connect(p.first, p.second);
    }
    vector<int> mapping = uf.get_mapping();

    for (auto &p : bridges) {
      p.first = mapping[p.first];
      p.second = mapping[p.second];
    }

    Graph g = Graph(n);
    for (auto p : bridges) {
      g.add_edge(p.first, p.second);
    }
    int li = g.longest(mapping[0]).second;
    cout << g.longest(li).first;
  }
};

class Solution {
 public:
  void solve() {
    int n, m;
    cin >> n >> m;

    Graph g = Graph(n);
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      g.add_edge(a - 1, b - 1);
    }

    g.solve();
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}