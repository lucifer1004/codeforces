#include <iostream>

using namespace std;
typedef long long ll;

class Solution {
 public:
  void solve() {
    int h, m;
    cin >> h >> m;
    cout << (24 - h) * 60 - m << endl;
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