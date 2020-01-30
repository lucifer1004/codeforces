#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

class Solution {
public:
  void solve() {
    ll a, m;
    scanf("%lld%lld", &a, &m);
    ll g = gcd(a, m);
    set<ll> factors;
    for (ll i = 1; i * i <= m; ++i) {
      if (m % i == 0) {
        if (i % g == 0)
          factors.insert(i);
        if (m / i % g == 0)
          factors.insert(m / i);
      }
    }
    vector<ll> f;
    for (ll factor : factors)
      f.emplace_back(factor / g);
    int v = f.size();
    vector<ll> u(v);
    u[0] = 1;
    for (int i = 0; i < v; ++i) {
      if (u[i] == 0)
        continue;
      for (int j = i + 1; j < v; ++j) {
        if (f[j] % f[i] == 0)
          u[j] -= u[i];
      }
    }
    ll ans = 0;
    for (int i = 0; i < v; ++i)
      ans += u[i] * m / g / f[i];
    cout << ans << endl;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  scanf("%d", &t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}