#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
public:
  void solve() {
    vector<ll> x(3);
    for (int i = 0; i < 3; ++i)
      cin >> x[i];
    sort(x.begin(), x.end());
    cout << 2 * max(x[2] - x[0] - 2, 0ll) << endl;
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