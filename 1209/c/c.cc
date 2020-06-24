#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i <= 9; ++i) {
      vector<int> ans(n);
      int amax = -1, bmax = -1;
      bool ok = true;
      for (int j = 0; j < n; ++j) {
        int d = s[j] - '0';
        if (d < i) {
          if (d < amax) {
            ok = false;
            break;
          }
          amax = max(amax, d);
          ans[j] = 1;
        } else if (d > i) {
          if (d < bmax) {
            ok = false;
            break;
          }
          bmax = max(bmax, d);
          ans[j] = 2;
        } else {
          if (bmax > i) {
            amax = max(amax, d);
            ans[j] = 1;
          } else {
            bmax = max(bmax, d);
            ans[j] = 2;
          }
        }
      }
      if (ok) {
        for (int j : ans)
          cout << j;
        cout << endl;
        return;
      }
    }
    cout << "-" << endl;
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