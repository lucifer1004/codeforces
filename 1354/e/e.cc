#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  bool invalid = false;
  vector<vector<int>> adj;
  vector<int> vis;
  vector<int> members;
  vector<vector<int>> odd, even;

  void dfs(int u) {
    members.emplace_back(u);
    for (int v : adj[u]) {
      if (vis[v] == 0) {
        vis[v] = vis[u] + 1;
        dfs(v);
      } else {
        if ((vis[v] - vis[u]) % 2 == 0) {
          invalid = true;
          return;
        }
      }
    }
  }

public:
  void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    adj = vector<vector<int>>(n + 1);
    for (int i = 0; i < m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
    }
    vis = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      if (!vis[i]) {
        members.clear();
        vis[i] = 1;
        dfs(i);
        vector<int> o, e;
        for (int i : members)
          if (vis[i] % 2 == 0)
            e.emplace_back(i);
          else
            o.emplace_back(i);
        even.push_back(e);
        odd.push_back(o);
      }
    }
    if (invalid) {
      printf("NO");
      return;
    }
    int g = even.size();
    vector<vector<bool>> dp(g + 1, vector<bool>(b + 1));
    vector<vector<int>> last(g + 1, vector<int>(b + 1, -1));
    dp[0][0] = true;
    for (int i = 1; i <= g; ++i) {
      int no = odd[i - 1].size();
      int ne = even[i - 1].size();
      for (int j = b; j >= min(no, ne); --j) {
        if (j >= no && dp[i - 1][j - no]) {
          dp[i][j] = true;
          last[i][j] = 1;
        }
        if (!dp[i][j] && j >= ne && dp[i - 1][j - ne]) {
          dp[i][j] = true;
          last[i][j] = 2;
        }
      }
    }
    if (!dp[g][b]) {
      printf("NO");
      return;
    }
    int curr = b;
    vector<int> two, others;
    for (int i = g; i >= 1; --i) {
      if (last[i][curr] == 1) {
        for (int j : odd[i - 1])
          two.emplace_back(j);
        for (int j : even[i - 1])
          others.emplace_back(j);
        curr -= odd[i - 1].size();
      } else {
        for (int j : even[i - 1])
          two.emplace_back(j);
        for (int j : odd[i - 1])
          others.emplace_back(j);
        curr -= even[i - 1].size();
      }
    }
    printf("YES\n");
    vector<int> ans(n + 1, 0);
    for (int i : two)
      ans[i] = 2;
    for (int i : others) {
      if (a > 0) {
        ans[i] = 1;
        a--;
      } else
        ans[i] = 3;
    }
    for (int i = 1; i <= n; ++i)
      printf("%d", ans[i]);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}