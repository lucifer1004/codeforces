#include <iostream>
#include <vector>

using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt = {0};
    for (char c : s)
      cnt.emplace_back(cnt.back() + (c == '1'));
    int ans = cnt[n];
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
      if (i < k)
        dp[i] = cnt[i - 1] + (s[i - 1] == '0');
      else {
        dp[i] = min(dp[i - k] + cnt[i - 1] - cnt[i - k], cnt[i - 1]) +
                (s[i - 1] == '0');
      }
      ans = min(ans, dp[i] + cnt[n] - cnt[i]);
    }
    cout << ans << endl;
  }
}