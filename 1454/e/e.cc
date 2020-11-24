#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

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
  bool loop_found = false;
  vector<vector<int>> adj;
  vector<int> depth, parent, cnt;
  vector<bool> in_loop;
  void dfs(int u) {
    for (int v : adj[u]) {
      if (v == parent[u])
        continue;
      if (loop_found)
        break;
      if (depth[v] != 0) {
        loop_found = true;
        int t = u;
        while (t != v) {
          in_loop[t] = true;
          t = parent[t];
        }
        in_loop[v] = true;
      } else {
        depth[v] = depth[u] + 1;
        parent[v] = u;
        dfs(v);
      }
    }
  }

  void dfs2(int u, int p) {
    for (int v : adj[u]) {
      if (v == p || in_loop[v])
        continue;
      dfs2(v, u);
      cnt[u] += cnt[v];
    }
  }

public:
  void solve() {
    int n;
    read(n);
    adj = vector<vector<int>>(n + 1);
    depth = vector<int>(n + 1);
    parent = vector<int>(n + 1);
    in_loop = vector<bool>(n + 1);
    for (int i = 1; i <= n; ++i) {
      int u, v;
      read(u), read(v);
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
    }
    depth[1] = 1;
    dfs(1);
    ll ans = (ll)n * (n - 1);
    cnt = vector<int>(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
      if (in_loop[i]) {
        dfs2(i, 0);
        ans -= (ll)cnt[i] * (cnt[i] - 1) / 2;
      }
    }
    printf("%lld\n", ans);
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
}