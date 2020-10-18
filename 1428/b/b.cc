#include <iostream>

using namespace std;

class Solution {
public:
  void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = 0, r = 0;
    for (char c : s) {
      if (c == '<')
        l++;
      if (c == '>')
        r++;
    }
    if (l == 0 || r == 0) {
      printf("%d\n", n);
      return;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int left = (i - 1 + n) % n;
      int right = i;
      if (s[left] == '-' || s[right] == '-')
        ans++;
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