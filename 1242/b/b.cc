#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

template <typename T> void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-')
      sig = -1;
  for (; isdigit(c); c = getchar())
    x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

class Solution {
  int ans = 0;
  vector<set<int>> adj;
  vector<bool> vis;
  set<int> rest;

  void dfs(int u) {
    vis[u] = true;
    vector<int> nxt;
    for (int v : rest)
      if (!adj[u].count(v))
        nxt.emplace_back(v);
    for (int v : nxt)
      rest.erase(v);
    for (int v : nxt)
      dfs(v);
  }

public:
  void solve() {
    int n, m;
    read(n), read(m);
    adj = vector<set<int>>(n + 1);
    for (int i = 0; i < m; ++i) {
      int u, v;
      read(u), read(v);
      adj[u].insert(v);
      adj[v].insert(u);
    }
    for (int i = 1; i <= n; ++i)
      rest.insert(i);
    vis = vector<bool>(n + 1);
    for (int i = 1; i <= n; ++i) {
      if (vis[i])
        continue;
      ans++;
      rest.erase(i);
      dfs(i);
    }
    printf("%d", ans - 1);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}