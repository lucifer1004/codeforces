#include <algorithm>
#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f

using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
  vector<int> len(n + 1, INF);
  for (int i = 0; i < n; ++i) {
    int balance = 0;
    for (int j = i; j < n; ++j) {
      balance += s[j] == '.' ? -1 : 1;
      if (balance < 0)
        break;
      if (balance == 0) {
        len[i + 1] = j - i + 1;
        break;
      }
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j <= m; ++j) {
      if (dp[i][j] == INF)
        continue;
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
      if (j < m && s[i] == t[j])
        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
      if (s[i] == '.' && j >= 1)
        dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j]);
      if (i + len[i + 1] <= n)
        dp[i + len[i + 1]][j] = min(dp[i + len[i + 1]][j], dp[i][j]);
    }
  cout << dp[n][m];
}