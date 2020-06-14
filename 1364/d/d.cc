#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define MAXN 100005

using namespace std;

vector<int> adj[MAXN];
int depth[MAXN], vis[MAXN], parent[MAXN];
class Solution {
  int n, m, k;
  void dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
      if (v == parent[u])
        continue;
      if (vis[v] == 0) {
        depth[v] = depth[u] + 1;
        parent[v] = u;
        dfs(v);
      } else if (vis[v] == 1) {
        int dist = depth[u] - depth[v] + 1;
        if (dist <= k) {
          printf("2\n");
          printf("%d\n", dist);
          int curr = u;
          while (depth[curr] >= depth[v]) {
            printf("%d ", curr);
            curr = parent[curr];
          }
          exit(0);
        }
      }
    }
    if (depth[u] == k) {
      vector<int> independent;
      int curr = u;
      while (curr != 0) {
        independent.emplace_back(curr);
        curr = parent[parent[curr]];
      }
      printf("1\n");
      for (int i : independent)
        printf("%d ", i);
      exit(0);
    }
    vis[u] = 2;
  }

public:
  void solve() {
    scanf("%d%d%d", &n, &m, &k);
    memset(depth, 0, sizeof(depth));
    memset(vis, 0, sizeof(vis));
    memset(parent, 0, sizeof(parent));
    for (int i = 0; i < m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
    }
    depth[1] = 1;
    dfs(1);
    printf("1\n");
    vector<int> odd;
    for (int i = 1; i <= n; ++i)
      if (depth[i] % 2 == 1)
        odd.emplace_back(i);
    if (odd.size() < (k + 1) / 2) {
      odd.clear();
      for (int i = 1; i <= n; ++i)
        if (depth[i] % 2 == 0)
          odd.emplace_back(i);
    }
    odd.resize((k + 1) / 2);
    for (int i : odd)
      printf("%d ", i);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}