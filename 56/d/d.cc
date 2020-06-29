#include <algorithm>
#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f

using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  vector<pair<int, int>> change = {{0, 0}, {-1, 0}, {0, -1}, {-1, -1}};
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
  vector<vector<int>> pre(n + 1, vector<int>(m + 1));
  dp[0][0] = 0;
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= m; ++j) {
      if (i == 0 && j == 0)
        continue;
      if (i > 0 && dp[i - 1][j] + 1 < dp[i][j]) {
        dp[i][j] = dp[i - 1][j] + 1;
        pre[i][j] = 1;
      }
      if (j > 0 && dp[i][j - 1] + 1 < dp[i][j]) {
        dp[i][j] = dp[i][j - 1] + 1;
        pre[i][j] = 2;
      }
      if (i > 0 && j > 0) {
        int nxt = dp[i - 1][j - 1] + (s[i - 1] == t[j - 1] ? 0 : 1);
        if (nxt < dp[i][j]) {
          dp[i][j] = nxt;
          pre[i][j] = 3;
        }
      }
    }
  int cx = n, cy = m;
  vector<int> seq;
  while (cx || cy) {
    int type = pre[cx][cy];
    seq.emplace_back(type);
    cx += change[type].first, cy += change[type].second;
  }
  reverse(seq.begin(), seq.end());
  vector<string> operations;
  for (int p : seq) {
    if (p == 3 && s[cx] != t[cy])
      operations.push_back("REPLACE " + to_string(cy + 1) + " " +
                           string{t[cy]});
    if (p == 1)
      operations.push_back("DELETE " + to_string(cy + 1));
    if (p == 2)
      operations.push_back("INSERT " + to_string(cy + 1) + " " + string{t[cy]});
    cx -= change[p].first, cy -= change[p].second;
  }
  cout << operations.size() << endl;
  for (const string &operation : operations)
    cout << operation << endl;
}