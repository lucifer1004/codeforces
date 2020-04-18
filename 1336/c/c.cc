#include <iostream>
#include <vector>

#define MOD 998244353

using namespace std;
typedef long long ll;

class Solution {
public:
  void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
    dp[n][0] = 1;
    for (int i = n - 1; i >= 1; --i) {
      dp[i][0] = i >= m ? n - i + 1 : (s[i] == t[i] ? dp[i + 1][0] : 0);
      dp[i][m] = dp[i + 1][m] * 2 % MOD;
      if (s[i] == t[m - 1])
        dp[i][m] = (dp[i][m] + dp[i + 1][m - 1]) % MOD;
      for (int j = 1; j < m; ++j) {
        if (i + j >= m || s[i] == t[i + j])
          dp[i][j] += dp[i + 1][j];
        if (s[i] == t[j - 1])
          dp[i][j] = (dp[i][j] + dp[i + 1][j - 1]) % MOD;
      }
    }
    ll ans = dp[1][m];
    for (int i = 0; i < m; ++i)
      if (t[i] == s[0])
        ans = (ans + dp[1][i]) % MOD;

    cout << ans * 2 % MOD;
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}