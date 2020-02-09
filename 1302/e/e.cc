#include <cstdio>
#include <iostream>

using namespace std;
typedef long long ll;

const int MOD = 1234567891;

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

ll rev(ll x) { return fexp(x, MOD - 2); }

class Solution {
public:
  void solve() {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    int ans = 1;
    int one = fexp(a * rev(b) % MOD, n);
    int zero = fexp((b - a) * rev(b) % MOD, n);
    ans = ((ans - one - zero) % MOD + MOD) % MOD;
    printf("%d", ans);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}