#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <vector>

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
  ll D;
  cin >> D;
  int q;
  cin >> q;
  map<ll, int> dict;
  set<ll> factors;
  vector<ll> fac(1000);
  fac[0] = 1;
  for (int i = 1; i < 1000; ++i)
    fac[i] = fac[i - 1] * i % MOD;
  vector<ll> rev(1000);
  for (int i = 0; i < 1000; ++i)
    rev[i] = fexp(fac[i], MOD - 2);
  for (ll i = 1; i * i <= D; ++i) {
    if (D % i == 0) {
      factors.insert(i);
      factors.insert(D / i);
    }
  }
  int idx = 0;
  for (ll factor : factors)
    dict[factor] = idx++;
  vector<ll> fv(factors.begin(), factors.end());
  vector<ll> primes;
  for (int i = 1; i < idx; ++i) {
    bool is_prime = true;
    for (int j = 1; j < i; ++j) {
      if (fv[i] % fv[j] == 0) {
        is_prime = false;
        break;
      }
    }
    if (is_prime)
      primes.emplace_back(fv[i]);
  }
  int prime_count = primes.size();
  vector<vector<int>> f(idx, vector<int>(prime_count));
  for (int i = 1; i < idx; ++i) {
    ll t = fv[i];
    for (int j = 0; j < prime_count; ++j) {
      while (t % primes[j] == 0) {
        t /= primes[j];
        f[i][j]++;
      }
    }
  }

  while (q--) {
    ll u, v;
    cin >> u >> v;
    int x = dict[u], y = dict[v];
    int down = 0, up = 0;
    for (int i = 0; i < prime_count; ++i)
      if (f[x][i] > f[y][i])
        down += f[x][i] - f[y][i];
      else if (f[x][i] < f[y][i])
        up += f[y][i] - f[x][i];
    ll ans = fac[up] * fac[down] % MOD;
    for (int i = 0; i < prime_count; ++i)
      if (f[x][i] != f[y][i])
        ans = ans * rev[abs(f[x][i] - f[y][i])] % MOD;
    cout << ans << endl;
  }
}