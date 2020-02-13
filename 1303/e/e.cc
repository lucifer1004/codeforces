#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void solve() {
    string s, t;
    cin >> s >> t;
    int ls = s.size(), lt = t.size();

    for (int left = 0; left < lt; ++left) {
      int right = lt - left;
      vector<int> dp{0};
      for (int i = 0; i < ls; ++i) {
        int len = dp.size();
        vector<int> ndp(dp);
        for (int j = 0; j < len; ++j) {
          if (j < left && s[i] == t[j]) {
            if (j == len - 1)
              ndp.emplace_back(dp[j]);
            else
              ndp[j + 1] = dp[j];
          }
          if (ndp[j] == right)
            continue;
          if (s[i] == t[left + dp[j]]) {
            ndp[j] = max(ndp[j], dp[j] + 1);
          }
        }
        swap(dp, ndp);
        if (dp.size() == left + 1 && dp[left] == right) {
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