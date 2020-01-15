#include <iostream>

using namespace std;
typedef long long ll;

class Solution {
 public:
  void solve() {
    int n, d;
    cin >> n >> d;
    for (int i = 0; i * i <= d; ++i) {
      int t = i + (d - 1) / (i + 1) + 1;
      if (t <= n) {
        cout << "YES" << endl;
        return;
      }
    }
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