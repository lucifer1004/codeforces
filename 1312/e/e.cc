#include <cstdio>
#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f

using namespace std;

class Solution {
public:
  void solve() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> f(n, vector<int>(n, -1));
    for (int i = 0; i < n; ++i) {
      int a;
      scanf("%d", &a);
      f[i][i] = a;
    }

    for (int len = 2; len <= n; ++len)
      for (int lo = 0; lo <= n - len; ++lo)
        for (int k = 1; k < len; ++k) {
          int mid = lo + k - 1;
          int hi = lo + len - 1;
          if (f[lo][mid] != -1 && f[lo][mid] == f[mid + 1][hi])
            f[lo][hi] = f[lo][mid] + 1;
        }

    vector<int> dp(n, INF);
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
      if (f[0][i] != -1)
        dp[i] = 1;
      for (int j = 0; j < i; ++j)
        if (f[j + 1][i] != -1)
          dp[i] = min(dp[i], dp[j] + 1);
    }

    printf("%d", dp[n - 1]);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}