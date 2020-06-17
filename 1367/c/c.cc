#include <iostream>

using namespace std;

class Solution {
public:
  void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    int l = 0;
    while (l != n && s[l] == '0')
      l++;
    if (l == n) {
      cout << (n - 1) / (k + 1) + 1 << endl;
      return;
    }
    int r = n - 1;
    while (r >= 0 && s[r] == '0')
      r--;
    ans += l / (k + 1) + (n - r - 1) / (k + 1);
    int cnt = 0;
    for (int i = l; i <= r; ++i) {
      if (s[i] == '0')
        cnt++;
      else {
        ans += (cnt - k) / (k + 1);
        cnt = 0;
      }
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