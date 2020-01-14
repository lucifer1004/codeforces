#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const ll modulo = 998244353;

class Solution {
  vector<ll> fac, rev, a;

  static ll fexp(ll x, ll y) {
    ll ans = 1;
    while (y > 0) {
      if (y % 2 == 1) ans = ans * x % modulo;
      y /= 2;
      x = x * x % modulo;
    }
    return ans;
  }

  ll C(ll n, ll k) {
    ll ans = fac[n] * rev[k] % modulo;
    ans = ans * rev[n - k] % modulo;
    return ans;
  }

 public:
  void solve() {
    int n;
    cin >> n;
    fac = vector<ll>(n + 1);
    rev = vector<ll>(n + 1);
    fac[0] = 1;
    for (ll i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % modulo;
    for (ll i = 0; i <= n; ++i) rev[i] = fexp(fac[i], modulo - 2);

    a = vector<ll>(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    ll sum = 0;
    vector<ll> f(n + 1);
    for (int i = n - 2; i >= 0; --i) {
      if (a[i] <= 0 || a[i] > n - 1 - i) continue;
      f[i] = C(n - 1 - i, a[i]);
      for (int j = i + a[i]; j < n; ++j) {
        ll left = C(j - i, a[i]);
        ll right = f[j + 1];
        f[i] = (f[i] + left * right) % modulo;
      }
      sum = (sum + f[i]) % modulo;
    }
    cout << sum;
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}