#include <cstdio>
#include <vector>

using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int main() {
  int n, k, m;
  scanf("%d%d%d", &n, &k, &m);
  vector<vector<pair<int, int>>> one(k), zero(k);
  for (int i = 0; i < m; ++i) {
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x);
    for (int j = 0; j < k; ++j)
      if (x & (1 << j))
        one[j].emplace_back(l, r);
      else
        zero[j].emplace_back(l, r);
  }
  ll ans = 1;
  for (int i = 0; i < k; ++i) {
    vector<int> one_end(n + 1, -1);
    vector<bool> must_one(n + 1);
    for (pair<int, int> segment : one[i])
      one_end[segment.first] = max(one_end[segment.first], segment.second);
    int rightmost = 0;
    for (int j = 1; j <= n; ++j) {
      rightmost = max(rightmost, one_end[j]);
      if (rightmost >= j)
        must_one[j] = true;
    }
    vector<int> f(n + 1);
    for (pair<int, int> segment : zero[i])
      f[segment.second] = max(f[segment.second], segment.first);
    for (int j = 2; j <= n; ++j)
      f[j] = max(f[j], f[j - 1]);
    vector<ll> dp(n + 1), sum(n + 1);
    rightmost = 0;
    for (int j = 1; j <= n; ++j) {
      if (!must_one[j])
        dp[j] =
            (sum[j - 1] - (rightmost == 0 ? -1 : sum[rightmost - 1]) + MOD) %
            MOD;
      sum[j] = (sum[j - 1] + dp[j]) % MOD;
      rightmost = max(rightmost, f[j]);
    }
    ll total =
        (sum[n] - (rightmost == 0 ? -1 : sum[rightmost - 1]) + MOD) % MOD;
    ans = ans * total % MOD;
  }
  printf("%lld", ans);
}