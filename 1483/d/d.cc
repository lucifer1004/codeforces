#include <cstdio>
#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f

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

    vector<vector<pair<int, int>>> adj(n);
    vector<vector<int>> dist(n, vector<int>(n, INF));

    for (int i = 0; i < m; ++i) {
      int u, v, w;
      read(u), read(v), read(w);
      u--, v--;
      adj[u].emplace_back(v, w);
      adj[v].emplace_back(u, w);
      dist[u][v] = dist[v][u] = w;
    }

    for (int k = 0; k < n; ++k)
      for (int i = 0; i < n; ++i) {
        if (i != k) {
          for (int j = i + 1; j < n; ++j) {
            if (j != k)
              dist[i][j] = dist[j][i] =
                  min(dist[i][j], dist[i][k] + dist[k][j]);
          }
        }
      }

    int q;
    read(q);
    vector<vector<int>> limit(n, vector<int>(n));
    for (int i = 0; i < q; ++i) {
      int u, v, l;
      read(u), read(v), read(l);
      u--, v--;
      limit[u][v] = limit[v][u] = l;
    }

    for (int k = 0; k < n; ++k)
      for (int u = 0; u < n; ++u) {
        if (u != k) {
          for (int v = u + 1; v < n; ++v) {
            if (v != k) {
              limit[v][k] = limit[k][v] =
                  max(limit[v][k], limit[u][v] - dist[u][k]);
              limit[u][k] = limit[k][u] =
                  max(limit[u][k], limit[u][v] - dist[v][k]);
            }
          }
        }
      }

    int ans = 0;
    for (int i = 0; i < n; ++i)
      for (auto [v, e] : adj[i])
        if (i < v && e <= limit[i][v]) ans++;

    printf("%d", ans);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}