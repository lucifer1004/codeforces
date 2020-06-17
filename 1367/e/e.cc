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
    vector<int> cnt(26);
    for (char c : s)
      cnt[c - 'a']++;
    int ans = 0;
    for (int i = 1; i <= min(n, k); ++i) {
      if (k % i != 0)
        continue;
      int l = 1, r = n / i;
      while (l <= r) {
        int mid = (l + r) >> 1;
        int tot = 0;
        for (int j = 0; j < 26; ++j)
          tot += cnt[j] / mid;
        if (tot >= i)
          l = mid + 1;
        else
          r = mid - 1;
      }
      ans = max(ans, r * i);
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