#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll fexp(ll x, ll y, ll mod) {
  ll ans = 1;
  while (y > 0) {
    if (y & 1)
      ans = ans * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}

class Solution {
public:
  void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    if (m == 1) {
      printf("0");
      return;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i)
      a[i] %= m;
    vector<ll> cnt(m), delta(m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j)
        delta[(a[i] + m - j) % m] += cnt[j];
      cnt[a[i]]++;
    }
    int ans = 1;
    for (int i = 0; i < m; ++i)
      ans = ans * fexp(i, delta[i], m) % m;
    printf("%d", ans);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}