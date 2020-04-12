#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int>> cnt(k, vector<int>(26));
    for (int i = 0; i < n; ++i)
      cnt[i % k][s[i] - 'a']++;
    int ans = 0;
    for (int i = 0; i * 2 < k; ++i) {
      int j = k - i - 1;
      int hi = 0;
      for (int p = 0; p < 26; ++p) {
        int curr = cnt[i][p] + (j != i ? cnt[j][p] : 0);
        hi = max(hi, curr);
      }
      int total = (j != i ? 2 * n / k : n / k);
      ans += total - hi;
    }
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