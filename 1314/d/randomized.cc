#include <cstdio>
#include <iostream>
#include <random>
#include <unordered_set>
#include <vector>
#define INF 0x3f3f3f3f
#define MAXN 80
#define MAXT 10240

using namespace std;

mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }

using namespace std;
int d[MAXN][MAXN];

class Solution {
  int n, k, ans;
  unordered_set<int> even, odd;

  void color() {
    even.clear(), odd.clear();
    even.insert(0);
    for (int i = 1; i < n; ++i)
      if (rnd(2))
        odd.insert(i);
      else
        even.insert(i);
    if (odd.empty())
      color();
  }

  void calculate_min() {
    vector<vector<int>> dp(k, vector<int>(n, INF));
    for (int v : odd)
      dp[1][v] = d[0][v];
    for (int i = 2; i < k; ++i) {
      if (i % 2 == 1) {
        for (int v : odd)
          for (int u : even)
            dp[i][v] = min(dp[i][v], dp[i - 1][u] + d[u][v]);
      } else {
        for (int v : even)
          for (int u : odd)
            dp[i][v] = min(dp[i][v], dp[i - 1][u] + d[u][v]);
      }
    }
    int result = INF;
    for (int u : odd)
      result = min(result, dp[k - 1][u] + d[u][0]);
    ans = min(ans, result);
  }

public:
  void solve() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
        scanf("%d", &d[i][j]);
      d[i][i] = INF;
    }

    ans = INF;
    for (int t = 0; t < MAXT; ++t) {
      color();
      calculate_min();
    }
    printf("%d", ans);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}