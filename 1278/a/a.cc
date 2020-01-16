#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

class Solution {
 public:
  void solve() {
    string p, h;
    cin >> p >> h;
    int lp = p.size(), lh = h.size();
    if (lp <= lh) {
      sort(p.begin(), p.end());
      for (int i = 0; i + lp <= lh; ++i) {
        string sub = h.substr(i, lp);
        sort(sub.begin(), sub.end());
        if (sub == p) {
          cout << "YES" << endl;
          return;
        }
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