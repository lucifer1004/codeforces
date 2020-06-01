#include <cstring>
#include <iostream>
#include <vector>
#define N 200005

using namespace std;
typedef long long ll;
vector<int> adj[N];
ll cost = 0;
ll a[N], lo[N];
int parent[N], b[N], c[N], zneed[N], ztot[N], changes[N], delta[N];
void dfs(int u) {
  ztot[u] = b[u] == 0;
  zneed[u] = c[u] == 0;
  changes[u] = b[u] != c[u];
  for (int v : adj[u]) {
    if (v != parent[u]) {
      parent[v] = u;
      lo[v] = min(lo[u], a[v]);
      dfs(v);
      ztot[u] += ztot[v];
      zneed[u] += zneed[v];
      changes[u] += changes[v];
    }
  }
}

void dfs2(int u) {
  for (int v : adj[u]) {
    if (v != parent[u]) {
      dfs2(v);
      delta[u] += delta[v];
    }
  }
  changes[u] -= delta[u];
  int zto = (changes[u] + ztot[u] - zneed[u]) / 2;
  int otz = (changes[u] + zneed[u] - ztot[u]) / 2;
  int change = min(zto, otz);
  cost += lo[u] * change * 2;
  delta[u] += change * 2;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i] >> b[i] >> c[i];
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  memset(parent, 0, sizeof(parent));
  memset(zneed, 0, sizeof(zneed));
  memset(ztot, 0, sizeof(ztot));
  memset(lo, 0, sizeof(lo));
  memset(changes, 0, sizeof(changes));
  lo[1] = a[1];
  dfs(1);
  if (zneed[1] != ztot[1]) {
    cout << -1;
    exit(0);
  }
  memset(delta, 0, sizeof(delta));
  dfs2(1);
  cout << cost;
}