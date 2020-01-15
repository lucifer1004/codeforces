#include <iostream>

using namespace std;
typedef long long ll;

class Solution {
 public:
  void solve() {
    ll A, B;
    cin >> A >> B;
    ll b = 0, c = 9;
    while (B >= c) {
      b++;
      c = c * 10 + 9;
    }
    cout << A * b << endl;
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
