#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
public:
  void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      p[i] = make_pair(x, y);
    }
    sort(p.begin(), p.end());
    string ans;
    int cx = 0, cy = 0;
    for (int i = 0; i < n; ++i) {
      while (cx < p[i].first) {
        cx++;
        ans += "R";
      }
      if (cy > p[i].second) {
        cout << "NO" << endl;
        return;
      }
      while (cy < p[i].second) {
        cy++;
        ans += "U";
      }
    }
    cout << "YES" << endl;
    cout << ans << endl;
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