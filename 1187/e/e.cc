#include <iostream>
#include <vector>
#define MAXN 200005

using namespace std;
typedef long long ll;
int n;
vector<int> adj[MAXN];
int parent[MAXN], cnt[MAXN];
ll down[MAXN], up[MAXN];
void dfs(int u, int p) {
  cnt[u] = 1;
  parent[u] = p;
  for (int v : adj[u]) {
    if (v != parent[u]) {
      dfs(v, u);
      cnt[u] += cnt[v];
    }
  }
}

void dfs2(int u) {
  down[u] = up[u] = 0;
  if (adj[u].size() == 1 && adj[u].front() == parent[u]) {
    down[u] = 1;
    up[u] = n;
    return;
  }
  for (int v : adj[u]) {
    if (v != parent[u]) {
      dfs2(v);
      down[u] += down[v];
    }
  }
  for (int v : adj[u]) {
    if (v != parent[u]) {
      up[u] = max(up[u], down[u] - down[v] + up[v] + n - cnt[v]);
    }
  }
  down[u] += cnt[u];
}
int main() {
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  dfs(1, -1);
  dfs2(1);
  cout << max(up[1], down[1]) << endl;
}