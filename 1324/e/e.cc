#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void solve() {
    int n, h, l, r;
    scanf("%d%d%d%d", &n, &h, &l, &r);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    vector<int> dp(h, -1);
    dp[0] = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      vector<int> ndp(h, -1);
      for (int j = 0; j < h; ++j) {
        if (dp[j] == -1)
          continue;
        for (int k : {-1, 0}) {
          int nxt = (j + a[i] + k) % h;
          int count = dp[j];
          if (nxt >= l && nxt <= r)
            count++;
          if (ndp[nxt] == -1 || ndp[nxt] < count)
            ndp[nxt] = count;
          ans = max(ans, count);
        }
      }
      swap(ndp, dp);
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