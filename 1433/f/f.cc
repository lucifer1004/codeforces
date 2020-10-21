#include <iostream>
#include <vector>
#define N 75

using namespace std;
int a[N][N];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> a[i][j];
  vector<int> g(k, -1);
  g[0] = 0;
  for (int i = 0; i < n; ++i) {
    int th = m / 2;
    vector<vector<int>> dp(th + 1, vector<int>(k, -1));
    dp[0][0] = 0;
    for (int j = 0; j < m; ++j) {
      vector<vector<int>> ndp(dp);
      for (int p = 0; p < th; ++p)
        for (int q = 0; q < k; ++q) {
          if (dp[p][q] < 0)
            continue;
          int nxt = (q + a[i][j]) % k;
          ndp[p + 1][nxt] = max(ndp[p + 1][nxt], dp[p][q] + a[i][j]);
        }
      dp = move(ndp);
    }
    vector<int> row(k, -1);
    for (int j = 0; j <= th; ++j)
      for (int q = 0; q < k; ++q)
        row[q] = max(row[q], dp[j][q]);
    vector<int> ng(g);
    for (int q = 0; q < k; ++q) {
      if (g[q] < 0)
        continue;
      for (int r = 0; r < k; ++r) {
        if (row[r] < 0)
          continue;
        int nxt = (q + r) % k;
        ng[nxt] = max(ng[nxt], g[q] + row[r]);
      }
    }
    g = move(ng);
  }
  cout << g[0];
}