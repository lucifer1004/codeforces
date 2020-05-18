#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        ll ai;
        cin >> ai;
        a[i][j] = ai - (i + j);
      }
    ll INF = 1e18;
    ll ans = INF;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        ll lo = a[i][j];
        vector<vector<ll>> dp(n, vector<ll>(m, INF));
        vector<vector<bool>> can(n, vector<bool>(m));
        can[0][0] = a[0][0] >= lo;
        dp[0][0] = a[0][0];
        for (int p = 0; p < n; ++p)
          for (int q = 0; q < m; ++q) {
            if (a[p][q] < lo || (p == 0 && q == 0))
              continue;
            if (p > 0 && can[p - 1][q]) {
              can[p][q] = true;
              dp[p][q] = dp[p - 1][q];
            }
            if (q > 0 && can[p][q - 1]) {
              can[p][q] = true;
              dp[p][q] = min(dp[p][q], dp[p][q - 1]);
            }
            if (can[p][q])
              dp[p][q] += a[p][q];
          }
        if (can[n - 1][m - 1])
          ans = min(ans, dp[n - 1][m - 1] - lo * (n + m - 1));
      }
    cout << ans << endl;
  }
}