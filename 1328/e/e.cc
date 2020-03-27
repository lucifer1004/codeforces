#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;
int n, m;
vector<int> depth;
vector<vector<int>> parent, adj;
string ans = "";

int pa(int u, int delta) {
  if (delta == 0)
    return u;
  for (int i = 19; i >= 0; --i)
    if (delta & (1 << i))
      u = parent[u][i];
  return u;
}

void query() {
  int k;
  scanf("%d", &k);
  vector<int> a(k);
  for (int i = 0; i < k; ++i)
    scanf("%d", &a[i]);
  sort(a.begin(), a.end(), [&](int i, int j) { return depth[i] > depth[j]; });
  int maxd = depth[a[0]];
  int node = a[0];
  bool ok = true;
  for (int i = 1; i < k; ++i) {
    int delta = maxd - depth[a[i]];
    maxd = depth[a[i]];
    node = pa(node, delta);
    if (parent[node][0] == parent[a[i]][0])
      continue;
    ok = false;
    break;
  }
  if (ok)
    ans += "YES\n";
  else
    ans += "NO\n";
}

void dfs(int u) {
  for (int v : adj[u])
    if (depth[v] == -1) {
      depth[v] = depth[u] + 1;
      parent[v][0] = u;
      int p = u;
      for (int i = 1; p != 0; p = parent[p][i - 1], i++)
        parent[v][i] = parent[p][i - 1];
      dfs(v);
    }
}

int main() {
  scanf("%d%d", &n, &m);
  adj.assign(n + 1, {});
  depth.assign(n + 1, -1);
  parent.assign(n + 1, vector<int>(20, 0));
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  depth[1] = 0;
  dfs(1);
  for (int i = 0; i < m; ++i)
    query();
  printf("%s", ans.c_str());
}