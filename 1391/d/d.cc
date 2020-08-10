#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f

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
public:
  void solve() {
    int n, m;
    read(n), read(m);
    vector<string> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    if (n >= 4 && m >= 4) {
      printf("-1");
      return;
    }
    if (n == 1 || m == 1) {
      printf("0");
      return;
    }
    int x = min(n, m), y = max(n, m);
    int k = (1 << x);
    vector<vector<int>> dp(y + 1, vector<int>(k, INF));
    vector<int> f(y);
    vector<vector<int>> cost(k, vector<int>(k));
    vector<vector<bool>> can(k, vector<bool>(k, true));
    for (int i = 0; i < k; ++i)
      for (int j = 0; j < k; ++j) {
        vector<int> ba(x), bb(x);
        for (int p = 0; p < x; ++p) {
          ba[p] = (i & (1 << p)) > 0;
          bb[p] = (j & (1 << p)) > 0;
          if (ba[p] != bb[p])
            cost[i][j]++;
        }
        for (int p = 0; p + 1 < x; ++p) {
          int cnt = ba[p] + bb[p] + ba[p + 1] + bb[p + 1];
          if (cnt % 2 == 0) {
            can[i][j] = false;
            break;
          }
        }
      }
    if (n < m) {
      for (int j = 0; j < m; ++j) {
        int cnt = 0;
        for (int i = 0; i < n; ++i)
          if (a[i][j] == '1')
            cnt ^= (1 << i);
        f[j] = cnt;
      }
    } else {
      for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < m; ++j)
          if (a[i][j] == '1')
            cnt ^= (1 << j);
        f[i] = cnt;
      }
    }
    for (int i = 0; i < k; ++i)
      dp[1][i] = cost[f[0]][i];
    for (int i = 2; i <= y; ++i)
      for (int last = 0; last < k; ++last)
        for (int now = 0; now < k; ++now) {
          if (can[last][now])
            dp[i][now] = min(dp[i][now], dp[i - 1][last] + cost[f[i - 1]][now]);
        }
    printf("%d", *min_element(dp[y].begin(), dp[y].end()));
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}