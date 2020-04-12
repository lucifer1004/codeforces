#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  int n;
  scanf("%d", &n);
  vector<ll> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%lld", &a[i]);
  map<ll, int> dict;
  vector<ll> dp(n, n);
  ll sum = 0;
  dict[0] = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i];
    if (dict.find(sum) != dict.end())
      dp[dict[sum]] = i;
    dict[sum] = i + 1;
  }
  ll ans = 0;
  ll rightmost = n;
  for (int i = n - 1; i >= 0; --i) {
    rightmost = min(rightmost, dp[i]);
    ans += rightmost - i;
  }
  printf("%lld", ans);
}