#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
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
 public:
  void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    int maxh = 0, hi = -1;
    for (int i = 0; i < n; ++i) {
      cin >> h[i];
      if (h[i] > maxh) {
        maxh = h[i];
        hi = i;
      }
    }
    rotate(h.begin(), h.begin() + hi, h.end());
    h.push_back(maxh);

    vector<ll> l(n + 1), r(n + 1), c(n + 1);
    for (int i = n - 1; i >= 0; --i) {
      r[i] = i + 1;
      while (r[i] < n && h[i] > h[r[i]]) r[i] = r[r[i]];
      if (r[i] < n && h[i] == h[r[i]]) {
        c[i] = c[r[i]] + 1;
        r[i] = r[r[i]];
      }
    }

    for (int i = 1; i < n; ++i) {
      l[i] = i - 1;
      while (l[i] > 0 && h[i] > h[l[i]]) l[i] = l[l[i]];
      if (l[i] < n && h[i] == h[l[i]]) {
        l[i] = l[l[i]];
      }
    }

    ll ans = 0;
    for (int i = 1; i < n; ++i) {
      ans += c[i] + 1;
      if (!(l[i] == 0 && r[i] == n)) ans++;
    }

    cout << ans;
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}