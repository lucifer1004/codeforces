#include <cmath>
#include <cstdio>
#include <iostream>
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

class Solution {
  vector<vector<int>> cnt;

public:
  void solve() {
    int n;
    read(n);
    string s;
    cin >> s;
    cnt = vector<vector<int>>(26, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i)
      for (int j = 0; j < 26; ++j)
        cnt[j][i] = cnt[j][i - 1] + (s[i - 1] - 'a' == j);
    int level = log2(n);
    vector<vector<int>> dp(level + 1, vector<int>(n));
    for (int i = 0; i <= level; ++i) {
      for (int j = 0; j < n; j += (1 << i)) {
        int c = level - i;
        if (i == 0)
          dp[i][j] = s[j] - 'a' == c ? 0 : 1;
        else {
          int half = 1 << (i - 1);
          int mid = j + half;
          int r = j + (1 << i);
          dp[i][j] = min(dp[i - 1][j] + half - (cnt[c][r] - cnt[c][mid]),
                         dp[i - 1][j + (1 << (i - 1))] + half -
                             (cnt[c][mid] - cnt[c][j]));
        }
      }
    }
    printf("%d\n", dp[level][0]);
  }
};

int main() {
  int t;
  read(t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}