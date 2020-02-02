#include <cstdio>
#include <iostream>

using namespace std;

class Solution {
public:
  void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans;
    for (int i = 0; i < n; ++i) {
      if ((s[i] - '0') % 2 == 1) {
        ans.push_back(s[i]);
      }
      if (ans.size() == 2) {
        cout << ans << endl;
        return;
      }
    }
    cout << -1 << endl;
    return;
  }
};

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}