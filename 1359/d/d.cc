#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  vector<int> dp(61, INT_MIN);
  dp[a[0] + 30] = 0;
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    vector<int> ndp(61, INT_MIN);
    int m = a[i] + 30;
    ndp[m] = 0;
    for (int k = 0; k <= 60; ++k) {
      if (dp[k] == INT_MIN)
        continue;
      if (k < m)
        ndp[m] = max(ndp[m], dp[k] + k - 30);
      else
        ndp[k] = max(ndp[k], dp[k] + m - 30);
    }
    ans = max(ans, *max_element(ndp.begin(), ndp.end()));
    swap(dp, ndp);
  }
  cout << ans;
}