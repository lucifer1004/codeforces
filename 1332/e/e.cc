#include <iostream>
#define MOD 998244353

using namespace std;
typedef long long ll;

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
  ll n, m, l, r;
  cin >> n >> m >> l >> r;
  ll half = (r - l + 1) / 2;
  ll odd = half, even = half;
  if (l % 2 == 0 && r % 2 == 0)
    even++;
  if (l % 2 == 1 && r % 2 == 1)
    odd++;
  if (n * m % 2 == 1)
    cout << fexp(r - l + 1, n * m) % MOD;
  else
    cout << (fexp(r - l + 1, n * m) + (odd == even ? 0 : 1)) *
                fexp(2, MOD - 2) % MOD;
}