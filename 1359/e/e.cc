#include <iostream>
#include <vector>
#define MAXN 500005

using namespace std;
typedef long long ll;
const ll MOD = 998244353;

ll fexp(ll x, ll y) {
  ll ans = 1;
  while (y > 0) {
    if (y & 1)
      ans = ans * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return ans;
}

int main() {
  int n, k;
  cin >> n >> k;
  if (n < k) {
    cout << 0;
    exit(0);
  }
  vector<ll> fac(n + 1);
  fac[0] = 1;
  for (int i = 1; i <= n; ++i)
    fac[i] = fac[i - 1] * i % MOD;
  vector<ll> rev(n + 1);
  for (int i = 0; i <= n; ++i)
    rev[i] = fexp(fac[i], MOD - 2);
  auto c = [&](int n, int k) {
    if (n < k)
      return 0ll;
    return fac[n] * rev[k] % MOD * rev[n - k] % MOD;
  };
  ll ans = 0;
  for (int i = 1; i * k <= n; ++i) {
    int m = n / i;
    ans += c(m, k) - c(m - 1, k);
    ans %= MOD;
    if (ans < 0)
      ans += MOD;
  }
  cout << ans;
}