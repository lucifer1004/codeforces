#include <iostream>

using namespace std;
typedef long long ll;

class Solution {
 public:
  void solve() {
    int n, k;
    cin >> n >> k;
    int rest = n % k;
    cout << n - rest + min(rest, k / 2) << endl;
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