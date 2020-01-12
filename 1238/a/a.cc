#include <iostream>

using namespace std;
typedef long long ll;

class Solution {
 public:
  void solve() {
    ll x, y;
    cin >> x >> y;
    cout << (x - y == 1 ? "NO" : "YES") << endl;
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