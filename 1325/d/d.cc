#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  ll x, y;
  cin >> x >> y;
  if (x > y || (x - y) % 2 != 0) {
    cout << -1;
    return 0;
  }
  bitset<64> a(x), b(y);
  vector<int> dp(64);
  for (int i = 0; i < 62; ++i)
    dp[i] = b[i];
  for (int i = 61; i >= 0; --i) {
    if (a[i]) {
      if (dp[i] == 0) {
        int j = i + 1;
        while (j <= 61 && dp[j] < 2)
          j++;
        if (j == 62) {
          cout << -1;
          return 0;
        } else {
          for (int k = j; k > i; --k) {
            dp[k] -= 2;
            dp[k - 1] += 4;
          }
          dp[i]--;
          dp[i - 1] += 2;
        }
      } else {
        if (dp[i] % 2 == 0) {
          dp[i]--;
          dp[i - 1] += 2;
        }
      }
    } else {
      if (dp[i] % 2 == 1) {
        dp[i]--;
        dp[i - 1] += 2;
      }
    }
  }
  int cnt = 0;
  for (int i : dp)
    cnt = max(cnt, i);
  vector<ll> ans;
  for (int i = 1; i <= cnt; ++i) {
    ll res = 0;
    for (int j = 0; j < 62; ++j)
      if (dp[j] >= i)
        res += 1ll << j;
    ans.emplace_back(res);
  }
  cout << ans.size() << endl;
  for (ll i : ans)
    cout << i << " ";
}