#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ll;

void solve() {
  int n;
  cin >> n;
  vector<int> h(n), c(n);
  for (int i = 0; i < n; ++i)
    scanf("%d%d", &h[i], &c[i]);
  vector<vector<ll>> dp(n, vector<ll>(3, LLONG_MAX));
  dp[0][0] = 0;
  dp[0][1] = c[0];
  dp[0][2] = c[0] * 2;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 3; ++j)
      for (int k = 0; k < 3; ++k) {
        if (h[i - 1] + j != h[i] + k)
          dp[i][k] = min(dp[i][k], dp[i - 1][j] + k * c[i]);
      }
  }
  cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])) << endl;
}

int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i)
    solve();
  return 0;
}