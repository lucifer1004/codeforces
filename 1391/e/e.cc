#include <cstdio>
#include <iostream>
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

string output;

class Solution {
  int md = 0, mdr = -1;
  vector<vector<int>> adj;
  vector<int> parent, depth;
  vector<bool> vis;
  void dfs(int u, int p) {
    vis[u] = true;
    depth[u] = depth[p] + 1;
    if (depth[u] > md) {
      md = depth[u];
      mdr = u;
    }
    parent[u] = p;
    for (int v : adj[u])
      if (!vis[v])
        dfs(v, u);
  }

public:
  void solve() {
    int n, m;
    read(n), read(m);
    int th = (n + 1) / 2;
    adj = vector<vector<int>>(n + 1);
    for (int i = 0; i < m; ++i) {
      int u, v;
      read(u), read(v);
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
    }
    parent = vector<int>(n + 1);
    depth = vector<int>(n + 1);
    vis = vector<bool>(n + 1);
    dfs(1, 0);
    if (md >= th) {
      output += "PATH\n" + to_string(md) + "\n";
      int p = mdr;
      while (p) {
        output += to_string(p) + " ";
        p = parent[p];
      }
      output += "\n";
      return;
    }
    vector<vector<int>> d(md + 1);
    for (int i = 1; i <= n; ++i)
      d[depth[i]].emplace_back(i);
    vector<pair<int, int>> ans;
    for (int i = 1; i <= md; ++i)
      for (int j = 1; j < d[i].size(); j += 2)
        ans.emplace_back(d[i][j - 1], d[i][j]);
    output += "PAIRING\n" + to_string(ans.size()) + "\n";
    for (auto &[u, v] : ans)
      output += to_string(u) + " " + to_string(v) + "\n";
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  read(t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
  printf("%s", output.c_str());
}