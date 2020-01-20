#include <algorithm>
#include <iostream>
#include <vector>
#define INF 3e16

using namespace std;
typedef long long ll;

class Solution {
public:
  void solve() {
    ll x0, y0, ax, ay, bx, by;
    ll xs, ys, t;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;
    vector<ll> x = {x0};
    vector<ll> y = {y0};
    while (true) {
      int n = x.size() - 1;
      ll nx = ax * x[n] + bx;
      ll ny = ay * y[n] + by;
      if (nx >= INF || ny >= INF)
        break;
      x.push_back(nx);
      y.push_back(ny);
    }

    ll ans = 0;
    ll n = x.size();
    for (int i = 0; i < n; ++i) {
      // Start from i-th node
      ll tu = abs(x[i] - xs) + abs(y[i] - ys);
      if (tu > t)
        continue;

      // Go left then right
      for (int j = i; j >= 0; --j) {
        // Stop at j-th node
        ll to = tu + abs(x[i] - x[j]) + abs(y[i] - y[j]);
        if (to > t)
          continue;
        ll collect = i - j + 1;
        for (int k = i + 1; k < n; ++k) {
          ll tp = to + abs(x[k] - x[j]) + abs(y[k] - y[j]);
          if (tp > t)
            break;
          collect = k - j + 1;
        }
        ans = max(ans, collect);
      }

      // Go right then left
      for (int j = i; j < n; ++j) {
        // Stop at j-th node
        ll to = tu + abs(x[i] - x[j]) + abs(y[i] - y[j]);
        if (to > t)
          break;
        ll collect = j - i + 1;
        for (int k = i - 1; k >= 0; --k) {
          ll tp = to + abs(x[k] - x[j]) + abs(y[k] - y[j]);
          if (tp > t)
            break;
          collect = j - k + 1;
        }
        ans = max(ans, collect);
      }
    }
    cout << ans;
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}