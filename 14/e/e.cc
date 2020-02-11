#include <cstdio>
#include <iostream>

using namespace std;
typedef long long ll;

ll dp[21][5][5][11][11]{};

class Solution {
public:
  void solve() {
    int n, t;
    scanf("%d%d", &n, &t);

    for (int i = 1; i <= 4; ++i)
      for (int j = 1; j <= 4; ++j)
        if (i != j)
          dp[2][i][j][0][0] = 1;

    for (int i = 3; i <= n; ++i)
      for (int p = 1; p <= 4; ++p)
        for (int q = 1; q <= 4; ++q) {
          if (p == q)
            continue;
          for (int r = 1; r <= 4; ++r) {
            if (q == r)
              continue;
            for (int x = 0; x <= t; ++x)
              for (int y = 0; y <= t - 1; ++y) {
                ll last = dp[i - 1][p][q][x][y];
                if (last == 0)
                  continue;
                if (p < q && q > r)
                  dp[i][q][r][x + 1][y] += last;
                else if (p > q && q < r)
                  dp[i][q][r][x][y + 1] += last;
                else
                  dp[i][q][r][x][y] += last;
              }
          }
        }

    ll ans = 0;
    for (int i = 1; i <= 4; ++i)
      for (int j = 1; j <= 4; ++j)
        if (i != j)
          ans += dp[n][i][j][t][t - 1];
    printf("%lld", ans);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}