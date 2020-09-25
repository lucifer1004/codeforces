#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#define MOD 998244353

using namespace std;
using ll = int64_t;

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

vector<ll> fac, inv;
ll C(int n, int k) {
  if (n < k)
    return 0;
  return fac[n] * inv[k] % MOD * inv[n - k] % MOD;
}

class Solution {
public:
  void solve() {
    int n, k;
    read(n), read(k);
    fac = vector<ll>(n + 1);
    inv = vector<ll>(n + 1);
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= n; ++i) {
      fac[i] = fac[i - 1] * i % MOD;
      inv[i] = fexp(fac[i], MOD - 2);
    }
    unordered_map<int, int> start, end;
    set<int> s;
    for (int i = 0; i < n; ++i) {
      int l, r;
      read(l), read(r);
      start[l]++, end[r]++;
      s.insert(l), s.insert(r);
    }
    ll ans = 0;
    int now = 0;
    for (int i : s) {
      if (now + start[i] >= k && start[i] > 0) {
        for (int j = max(1, k - now); j <= min(k, start[i]); ++j)
          ans += C(now, k - j) * C(start[i], j) % MOD;
        ans %= MOD;
      }
      now += start[i] - end[i];
    }
    printf("%lld", ans);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}