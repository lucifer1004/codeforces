#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-') sig = -1;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

class Solution {
 public:
  void solve() {
    int n;
    read(n);
    vector<int> tag(n), score(n);
    for (int i = 0; i < n; ++i) read(tag[i]);
    for (int i = 0; i < n; ++i) read(score[i]);
    vector<ll> dp(n);
    for (int i = 1; i < n; ++i)
      for (int j = i - 1; j >= 0; --j) {
        if (tag[i] != tag[j]) {
          ll delta = abs(score[i] - score[j]);
          ll dpj = dp[i] + delta, dpi = dp[j] + delta;
          dp[i] = max(dp[i], dpi);
          dp[j] = max(dp[j], dpj);
        }
      }
    ll ans = *max_element(dp.begin(), dp.end());
    printf("%lld\n", ans);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  read(t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}