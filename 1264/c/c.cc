#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define MOD 998244353ll

using namespace std;
typedef long long ll;

mt19937 mrand(random_device{}());

int rnd(int x) { return mrand() % x; }

ll fexp(ll x, ll y) {
  ll ans = 1;
  while (y > 0) {
    if (y % 2 == 1)
      ans = ans * x % MOD;
    x = x * x % MOD;
    y /= 2;
  }
  return ans;
}

ll rev(ll x) { return fexp(x, MOD - 2); }

class Solution {
  int n, q;
  ll ans;
  vector<ll> p, s, t;
  set<int> checkpoints;

  ll mul(int i, int j) { return t[j] * rev(t[i - 1]) % MOD; }

  ll expectation(int i, int j) {
    ll delta = s[i - 1] * mul(i, j) % MOD;
    return (s[j] - delta + MOD) % MOD;
  }

  void update(int i) {
    bool exist = checkpoints.find(i) != checkpoints.end();
    if (exist)
      checkpoints.erase(i);
    auto it_lo = prev(checkpoints.lower_bound(i));
    int lo = *it_lo;
    auto it_hi = checkpoints.upper_bound(i);
    int hi = it_hi == checkpoints.end() ? n + 1 : *it_hi;
    if (exist) {
      ans = (ans - expectation(lo, i - 1)) % MOD;
      ans = (ans - expectation(i, hi - 1)) % MOD;
      ans = (ans + expectation(lo, hi - 1)) % MOD;
      ans = (ans + MOD) % MOD;
    } else {
      ans = (ans + expectation(lo, i - 1)) % MOD;
      ans = (ans + expectation(i, hi - 1)) % MOD;
      ans = (ans - expectation(lo, hi - 1)) % MOD;
      ans = (ans + MOD) % MOD;
      checkpoints.insert(i);
    }
  }

  void query() { printf("%lld\n", ans); }

public:
  void solve() {
    scanf("%d %d", &n, &q);
    p = vector<ll>(n + 1);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &p[i]);
      p[i] = 100 * rev(p[i]) % MOD;
    }

    s = vector<ll>(n + 1);
    t = vector<ll>(n + 1);
    t[0] = 1;
    for (int i = 1; i <= n; ++i) {
      s[i] = (s[i - 1] + 1) * p[i] % MOD;
      t[i] = t[i - 1] * p[i] % MOD;
    }
    ans = expectation(1, n);
    checkpoints.insert(1);

    for (int i = 1; i <= q; ++i) {
      int idx;
      scanf("%d", &idx);
      update(idx);
      query();
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}