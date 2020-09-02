#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
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

bool f[10][10][10][10];

class Solution {
  vector<vector<pair<int, int>>> adj;
  vector<vector<int>> in;
  int ans = 0, n, m, k;

  void dfs(vector<int> &choose, int d) {
    if (d == k + 1) {
      bool ok = true;
      for (int i = 1; i <= k; ++i)
        for (int j = 1; j <= k; ++j)
          if (f[i][choose[i]][j][choose[j]])
            ok = false;
      if (ok)
        ans++;
      return;
    }
    if (choose[d] == 0) {
      for (int i = 1; i <= d; ++i) {
        bool ok = true;
        for (int j = 1; j < d; ++j)
          if (f[j][choose[j]][d][i]) {
            ok = false;
            break;
          }
        if (!ok)
          continue;
        choose[d] = i;
        dfs(choose, d + 1);
        choose[d] = 0;
      }
    } else
      dfs(choose, d + 1);
  }

public:
  void solve() {
    read(n), read(m), read(k);
    adj = vector<vector<pair<int, int>>>(n + 1);
    in = vector<vector<int>>(n + 1);
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      read(u), read(v), read(w);
      adj[u].emplace_back(w, v);
      in[v].emplace_back(u);
    }
    for (int i = 1; i <= n; ++i)
      sort(adj[i].begin(), adj[i].end());

    vector<int> choose(k + 1);
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; ++i) {
      map<pair<int, int>, int> s;
      for (int u : in[i]) {
        int k = 0;
        while (adj[u][k].second != i)
          k++;
        int t = adj[u].size();
        s[{t, k + 1}]++;
      }
      for (auto &[p, pc] : s) {
        if (pc > 1) {
          for (int i = 1; i <= k; ++i)
            for (int j = 1; j <= i; ++j)
              f[i][j][p.first][p.second] = true,
              f[p.first][p.second][i][j] = true;
          continue;
        }
        for (auto &[q, qc] : s)
          if (p != q)
            f[p.first][p.second][q.first][q.second] = true;
      }
    }

    for (int i = 1; i <= n; ++i) {
      if (in[i].empty()) {
        printf("0");
        return;
      }
      if (in[i].size() == 1) {
        int u = in[i][0];
        int k = 0;
        while (adj[u][k].second != i)
          k++;
        int t = adj[u].size();
        if (choose[t] != 0 && choose[t] != k + 1) {
          printf("0");
          return;
        }
        choose[t] = k + 1;
      }
    }

    dfs(choose, 1);
    printf("%d", ans);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}