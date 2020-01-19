#include <iostream>

using namespace std;
typedef long long ll;

class Solution {
  ll count(ll n, ll m) {
    if (m > n)
      return 0;
    if (m % 2 == 1)
      return count(n, 2 * m) + 1;
    ll ans = 0, level = 2;
    while (m <= n) {
      ans += min(level, n - m + 1);
      m *= 2;
      level *= 2;
    }
    return ans;
  }

  ll solve_odd(ll n, ll k) {
    ll l = 1, r = (n + 1) / 2;
    while (l <= r) {
      ll mid = (l + r) / 2;
      ll cmid = count(n, mid * 2 - 1);
      ll cnext = count(n, mid * 2 + 1);
      if (cmid >= k && cnext < k)
        return mid * 2 - 1;
      if (cnext >= k)
        l = mid + 1;
      if (cmid < k)
        r = mid - 1;
    }
    return 0;
  }

  ll solve_even(ll n, ll k) {
    ll l = 1, r = n / 2;
    while (l <= r) {
      ll mid = (l + r) / 2;
      ll cmid = count(n, mid * 2);
      ll cnext = count(n, mid * 2 + 2);
      if (cmid >= k && cnext < k)
        return mid * 2;
      if (cnext >= k)
        l = mid + 1;
      if (cmid < k)
        r = mid - 1;
    }
    return 0;
  }

public:
  void solve() {
    ll n, k;
    cin >> n >> k;

    ll odd = solve_odd(n, k);
    ll even = solve_even(n, k);
    cout << max(odd, even);
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}