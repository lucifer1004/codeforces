#include <iostream>
#include <set>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
  vector<ll> primes = {2, 3, 5, 7, 11, 13, 17, 19};

  ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }

 public:
  void solve() {
    ll n;
    cin >> n;

    for (ll j = 23; j * j <= n; ++j) {
      bool prime = true;
      for (ll i = 0; primes[i] * primes[i] <= j; ++i) {
        if (j % primes[i] == 0) {
          prime = false;
          break;
        }
      }
      if (prime) primes.emplace_back(j);
    }

    set<ll> factors;
    for (ll i = 0; i < primes.size(); ++i) {
      while (n % primes[i] == 0) {
        n /= primes[i];
        factors.insert(primes[i]);
      }
    }

    if (n != 1) factors.insert(n);
    if (factors.empty() || factors.size() >= 2)
      cout << 1 << endl;
    else
      cout << *factors.begin() << endl;
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}