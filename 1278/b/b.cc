#include <cmath>
#include <iostream>

using namespace std;
typedef long long ll;

class Solution {
 public:
  void solve() {
    int a, b;
    cin >> a >> b;
    int sum = a + b;
    int target = max(a, b);

    while (true) {
      int rest = target * 2 - sum;
      int n = sqrt(rest * 2);
      if (n * (n + 1) / 2 == rest) {
        cout << n << endl;
        break;
      }
      target++;
    }
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
