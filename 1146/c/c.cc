#include <iostream>
#include <set>

using namespace std;

class Solution {
 public:
  void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i <= 7; ++i) {
      set<int> zero, one;
      for (int j = 1; j <= n; ++j) {
        if (j & (1 << i))
          one.insert(j);
        else
          zero.insert(j);
      }
      int k1 = zero.size(), k2 = one.size();
      if (k1 >= 1 && k2 >= 1) {
        cout << k1 << " " << k2 << " ";
        for (int num : zero) cout << num << " ";
        for (int num : one) cout << num << " ";
        cout << endl;
        int res;
        cin >> res;
        ans = max(ans, res);
      }
    }
    cout << -1 << " " << ans << endl;
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