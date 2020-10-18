#include <iostream>

using namespace std;

class Solution {
public:
  void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = n;
    int bal = 0, left = 0;
    for (char c : s) {
      if (c == 'A') {
        bal++;
      } else {
        if (bal > 0) {
          bal--;
          ans -= 2;
        } else
          left++;
      }
    }
    cout << ans - (left - left % 2) << endl;
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