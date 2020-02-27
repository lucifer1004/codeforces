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
#define INF 0x3f3f3f3f
#define MOD 1000000007

using namespace std;
typedef unsigned long long ll;

class Solution {
  ll lowbit(ll x) { return x & (-x); }

  ll f(ll l, ll r) {
    if (l >= r)
      return 0;
    if (l == 0)
      return f(1, r) + r * 2 - 1;
    if (l & 1)
      return f(l + 1, r) + (g(l, r) - g(l, l)) * 2;
    if (r & 1)
      return f(l, r - 1) + (g(r - 1, r) - g(r - 1, l)) * 2;
    return f(l >> 1, r >> 1) * 3;
  }

  ll g(ll x, ll n) {
    ll ans = 0;
    while (n > 0) {
      ans += h(x, n);
      n -= lowbit(n);
    }
    return ans;
  }

  ll h(int x, int n) {
    ll lo = lowbit(n);
    ll left = n - lo;
    if (x & left)
      return 0;
    ll num = 0;
    while (lo > 1) {
      num++;
      lo >>= 1;
    }
    ll count = 0;
    for (int i = 0; i < num; ++i) {
      count += (x & 1);
      x >>= 1;
    }
    return 1ull << (num - count);
  }

public:
  void solve() {
    ll l, r;
    scanf("%lld%lld", &l, &r);
    printf("%lld\n", f(l, r + 1));
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  scanf("%d", &t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}