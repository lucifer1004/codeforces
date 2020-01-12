#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
 public:
  void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> f(n + 1);
    int ans = 0, hi = 0;
    for (int i = 2; i <= n; ++i) {
      if (s[i - 1] == '(')
        f[i] = 0;
      else {
        if (f[i - 1] < i - 1 && s[i - 2 - f[i - 1]] == '(')
          f[i] = f[i - 1] + 2 + f[i - 2 - f[i - 1]];
        hi = max(hi, f[i]);
      }
    }

    for (int i = 2; i <= n; ++i) ans += f[i] == hi;

    cout << (hi == 0 ? "0 1" : to_string(hi) + " " + to_string(ans));
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}