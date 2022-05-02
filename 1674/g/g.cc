#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-') sig = -1;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

class Solution {
 public:
  void solve() {
    int n, m;
    read(n), read(m);
    vector<vector<int>> adj(n), useful(n), rev(n);
    vector<unordered_set<int>> bad(n);

    vector<int> indegree(n);
    for (int i = 0; i < m; ++i) {
      int u, v;
      read(u), read(v);
      u--, v--;
      adj[u].push_back(v);
      rev[v].push_back(u);
      indegree[v]++;
    }

    for (int i = 0; i < n; ++i) {
      if (rev[i].size() == 1) {
        int u = rev[i][0];
        bad[u].insert(i);
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int v : adj[i]) {
        if (!bad[i].count(v)) useful[i].push_back(v);
      }
    }

    vector<int> dp(n);
    queue<int> q;
    for (int i = 0; i < n; ++i)
      if (indegree[i] == 0) q.push(i);

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      dp[u] = max(dp[u], 1);
      if (adj[u].size() >= 2)
        for (int v : useful[u]) dp[v] = max(dp[v], dp[u] + 1);
      for (int v : adj[u]) {
        indegree[v]--;
        if (indegree[v] == 0) q.push(v);
      }
    }

    printf("%d\n", *max_element(dp.begin(), dp.end()));
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}