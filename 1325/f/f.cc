#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> vis, depth, parent, ans;
vector<vector<int>> adj;
unordered_set<int> indep;
int threshold;
void dfs(int u) {
  int back = 0, dist = 0;
  vis[u] = 1;
  for (int v : adj[u]) {
    if (v == parent[u])
      continue;
    switch (vis[v]) {
    case 0:
      parent[v] = u;
      depth[v] = depth[u] + 1;
      dfs(v);
      break;
    case 1:
      back++;
      dist = max(dist, depth[u] - depth[v]);
    }
  }
  if (dist >= threshold - 1) {
    cout << 2 << endl;
    cout << dist + 1 << endl;
    int curr = u;
    while (dist >= 0) {
      cout << curr << " ";
      curr = parent[curr];
      dist--;
    }
    exit(0);
  }
  if (back < threshold - 1) {
    bool ok = true;
    for (int v : adj[u])
      if (indep.find(v) != indep.end()) {
        ok = false;
        break;
      }
    if (ok)
      indep.insert(u);
    if (indep.size() == threshold) {
      cout << 1 << endl;
      for (int i : indep)
        cout << i << " ";
      exit(0);
    }
  }
  vis[u] = 2;
};

int main() {
  int n, m;
  cin >> n >> m;
  adj.assign(n + 1, {});
  depth.assign(n + 1, 0);
  parent.assign(n + 1, 0);
  vis.assign(n + 1, 0);
  threshold = int(ceil(sqrt(n)));
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  dfs(1);
}