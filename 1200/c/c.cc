#include <algorithm>
#include <bitset>
#include <climits>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
  ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

  ll room(ll x, ll y, ll n, ll m, ll g) {
    if (g == 1) return 1;
    if (x == 1) {
      return (y - 1) / (n / g) + 1;
    } else {
      return (y - 1) / (m / g) + 1;
    }
  }

 public:
  void solve() {
    ll n, m, q;
    cin >> n >> m >> q;
    ll g = gcd(n, m);
    for (int i = 0; i < q; ++i) {
      ll sx, sy, ex, ey;
      cin >> sx >> sy >> ex >> ey;
      ll s = room(sx, sy, n, m, g);
      ll e = room(ex, ey, n, m, g);
      cout << (s == e ? "YES" : "NO") << endl;
    }
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}