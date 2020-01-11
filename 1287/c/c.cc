#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  int dp[101][2][51];
  memset(dp, 100, sizeof(dp));
  dp[0][0][0] = 0;
  dp[0][1][0] = 0;
  for (int i = 1; i <= n; ++i) {
    if (b[i - 1] == 0 || b[i - 1] % 2 == 1) {
      for (int odd = 1; odd <= min(i, (n + 1) / 2); ++odd) {
        int even = i - odd;
        if (even > n / 2) continue;
        dp[i][1][odd] = min(dp[i - 1][1][odd - 1], dp[i - 1][0][odd - 1] + 1);
      }
    }

    if (b[i - 1] == 0 || b[i - 1] % 2 == 0) {
      for (int odd = 0; odd <= min(i, (n + 1) / 2); ++odd) {
        int even = i - odd;
        if (even > n / 2) continue;
        dp[i][0][odd] = min(dp[i - 1][0][odd], dp[i - 1][1][odd] + 1);
      }
    }
  }
  cout << min(dp[n][0][(n + 1) / 2], dp[n][1][(n + 1) / 2]);
}

int main() { solve(); }