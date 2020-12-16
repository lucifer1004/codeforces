#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <vector>
#define MOD 1000000007
#define MAXN 200005

using namespace std;
typedef long long ll;

ll fac[MAXN], inv[MAXN], invfac[MAXN];
ll C(int n, int k) { return fac[n] * invfac[k] % MOD * invfac[n - k] % MOD; }

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

class Solution {
public:
  void solve() {
    int n, m, k;
    read(n), read(m), read(k);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      read(a[i]);
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = m - 1; i < n; ++i) {
      auto it = lower_bound(a.begin(), a.end(), a[i] - k);
      int len = a.begin() + i - it;
      if (len >= m - 1)
        ans = (ans + C(len, m - 1)) % MOD;
    }
    printf("%lld\n", ans);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  fac[0] = invfac[0] = fac[1] = invfac[1] = inv[1] = 1;
  for (int i = 2; i < MAXN; ++i) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = -inv[MOD % i] * (MOD / i) % MOD + MOD;
    invfac[i] = invfac[i - 1] * inv[i] % MOD;
  }

  int t;
  read(t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}