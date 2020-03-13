#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  vector<vector<int>> adj;
  vector<int> parent, color, sum, ans;
  void dfs(int u) {
    sum[u] = color[u] * 2 - 1;
    for (int v : adj[u]) {
      if (v != parent[u]) {
        parent[v] = u;
        dfs(v);
        if (sum[v] >= 0)
          sum[u] += sum[v];
      }
    }
  }

  void dfs2(int u) {
    ans[u] = sum[u];
    int p = parent[u];
    if (p != -1) {
      int rest = ans[p];
      if (sum[u] > 0)
        rest -= sum[u];
      if (rest > 0)
        ans[u] += rest;
    }
    for (int v : adj[u])
      if (v != p)
        dfs2(v);
  }

public:
  void solve() {
    int n;
    scanf("%d", &n);
    color.assign(n, 0);
    for (int i = 0; i < n; ++i)
      scanf("%d", &color[i]);
    adj.assign(n, {});
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
    }
    parent.assign(n, -1);
    sum.assign(n, 0);
    ans.assign(n, 0);
    dfs(0);
    dfs2(0);
    for (int i : ans)
      printf("%d ", i);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}