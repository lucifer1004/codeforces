#include <cstdio>
#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;
using ll = long long;

template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-') sig = -1;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

const int K = 63;
ll C[1005][1005];

class Solution {
 public:
  ll solve(int n, ll r, ll z) {
    vector<ll> dp(n + 1);
    dp[0] = 1;

    for (int i = K - 1; i >= 0; --i) {
      int z_parity = ((z & (1LL << i)) == 0) ? 0 : 1;
      int r_parity = ((r & (1LL << i)) == 0) ? 0 : 1;
      vector<ll> ndp(n + 1);

      for (int j = 0; j <= n; ++j) {
        for (int k = z_parity; k <= n; k += 2) {
          int nxt = min(n, j * 2 + r_parity - k);
          if (nxt < 0) continue;
          ndp[nxt] = (ndp[nxt] + dp[j] * C[n][k] % MOD) % MOD;
        }
      }

      dp = move(ndp);
    }

    ll ans = 0;
    for (ll x : dp) ans = (ans + x) % MOD;

    return ans;
  }

  void solve() {
    int n;
    ll l, r, z;
    read(n), read(l), read(r), read(z);

    ll ans = (solve(n, r, z) + MOD - solve(n, l - 1, z)) % MOD;
    printf("%lld\n", ans);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  for (int i = 1; i <= 1000; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
  }

  Solution solution = Solution();
  solution.solve();
}