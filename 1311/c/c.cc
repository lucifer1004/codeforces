#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void solve() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<vector<int>> cnt(n + 1, vector<int>(26));
    for (int i = 1; i <= n; ++i)
      for (int j = 0; j < 26; ++j) {
        cnt[i][j] = cnt[i - 1][j];
        if (j == s[i - 1] - 'a')
          cnt[i][j]++;
      }

    vector<int> ans(26);
    for (int i = 0; i < m; ++i) {
      int p;
      cin >> p;
      for (int j = 0; j < 26; ++j)
        ans[j] += cnt[p][j];
    }
    for (int j = 0; j < 26; ++j)
      cout << ans[j] + cnt[n][j] << " ";
    cout << endl;
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