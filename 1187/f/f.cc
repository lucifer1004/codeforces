#include <cstdio>
#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;
typedef long long ll;

template <typename T> void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-')
      sig = -1;
  for (; isdigit(c); c = getchar())
    x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

ll fexp(ll x, ll y) {
  ll ans = 1;
  while (y) {
    if (y & 1)
      ans = ans * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return ans;
}

ll rev(ll x) { return fexp(x, MOD - 2); }
template <typename T> T min(T a, T b, T c) { return min(a, min(b, c)); }
template <typename T> T max(T a, T b, T c) { return max(a, max(b, c)); }

class Solution {
public:
  void solve() {
    int n;
    read(n);
    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i)
      read(l[i]);
    for (int i = 0; i < n; ++i) {
      read(r[i]);
      r[i]++;
    }
    vector<ll> q(n);
    for (int i = 1; i < n; ++i) {
      ll delta = min(r[i - 1], r[i]) - max(l[i - 1], l[i]);
      if (delta <= 0)
        continue;
      q[i] = delta * rev(r[i - 1] - l[i - 1]) % MOD * rev(r[i] - l[i]) % MOD;
    }
    vector<ll> p(n);
    for (int i = 0; i < n; ++i)
      p[i] = (1 + MOD - q[i]) % MOD;
    vector<ll> qq(n);
    for (int i = 1; i < n - 1; ++i) {
      ll delta = min(r[i - 1], r[i], r[i + 1]) - max(l[i - 1], l[i], l[i + 1]);
      if (delta <= 0)
        continue;
      qq[i] = delta * rev(r[i - 1] - l[i - 1]) % MOD * rev(r[i] - l[i]) % MOD *
              rev(r[i + 1] - l[i + 1]) % MOD;
    }
    vector<ll> pp(n);
    for (int i = 0; i < n - 1; ++i) {
      pp[i] = (1 - q[i] - q[i + 1] + qq[i]) % MOD;
      if (pp[i] < 0)
        pp[i] += MOD;
    }
    ll sum = 0;
    for (int i = 0; i < n; ++i)
      sum = (sum + p[i]) % MOD;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
      ll curr = p[i] +
                p[i] * (sum - (i >= 1 ? p[i - 1] : 0) - p[i] -
                        (i < n - 1 ? p[i + 1] : 0)) +
                (i >= 1 ? pp[i - 1] : 0) + pp[i];
      curr %= MOD;
      ans = (ans + curr) % MOD;
    }
    if (ans < 0)
      ans += MOD;
    cout << ans;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}