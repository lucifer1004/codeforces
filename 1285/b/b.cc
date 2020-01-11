#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
 public:
  void solve() {
    int n;
    cin >> n;
    vector<ll> t(n);
    ll yasser = 0, adel = INT_MIN;
    for (int i = 0; i < n; ++i) {
      cin >> t[i];
      yasser += t[i];
    }
    vector<ll> f(n + 1);
    for (int i = 0; i < n; ++i) {
      f[i + 1] = t[i] + max(f[i], 0ll);
      adel = max(adel, f[i + 1]);
    }

    // Special case
    if (f[n] == adel) {
      adel = INT_MIN;
      for (int i = 1; i <= n - 1; ++i) {
        adel = max(adel, f[i]);
      }

      ll sum = 0;
      for (int i = n; i >= 2; --i) {
        sum += t[i - 1];
        adel = max(adel, sum);
      }
    }

    if (yasser > adel)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}