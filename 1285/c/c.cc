#include <iostream>

using namespace std;
typedef long long ll;

class Solution {
  ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

 public:
  void solve() {
    ll x;
    cin >> x;
    ll a, b;
    for (ll i = 1; i * i <= x; ++i) {
      ll ai = i, bi = x / i;
      if (x % i == 0 && gcd(ai, bi) == 1) {
        a = ai;
        b = bi;
      }
    }
    cout << a << " " << b;
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}