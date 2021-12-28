#include <iostream>
#include <vector>
#define MOD 998244353
#define MAXN 5005

using namespace std;
using ll = long long;

ll fac[MAXN], ifac[MAXN];

ll fexp(ll x, ll y) {
  ll ans = 1;
  while (y) {
    if (y & 1) ans = ans * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return ans;
}

inline ll inv(ll x) { return fexp(x, MOD - 2); }

ll C(int n, int k) { return fac[n] * ifac[k] % MOD * ifac[n - k] % MOD; }

int main() {
  int n, k;
  string s;

  cin >> n >> k >> s;

  fac[0] = ifac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % MOD;

  ifac[n] = inv(fac[n]);
  for (int i = n - 1; i >= 1; --i) ifac[i] = ifac[i + 1] * (i + 1) % MOD;

  vector<int> ones;
  for (int i = 0; i < n; ++i)
    if (s[i] == '1') ones.push_back(i);

  if (ones.size() < k || k == 0) {
    cout << 1 << endl;
    return 0;
  }

  ll ans = 1;
  for (int i = 0; i < ones.size(); ++i) {
    // i-th '1' moved
    int l = i == 0 ? 0 : ones[i - 1] + 1;
    int m = min(k, (int)ones.size() - i);
    int r = i + m >= ones.size() ? n - m : ones[i + m] - m;
    for (int j = l; j <= r; ++j) {
      if (j == ones[i]) continue;
      int rk = i + m >= ones.size() ? n - 1 : ones[i + m] - 1;
      ans = (ans + C(rk - j, m - 1)) % MOD;
    }
  }

  cout << ans << endl;
}