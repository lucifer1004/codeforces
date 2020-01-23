#include <iostream>

using namespace std;
typedef long long ll;

class Solution {
public:
  void solve() {
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    int hi = max(a, max(b, c));
    int delta = hi * 3 - a - b - c;
    if (n < delta || (n - delta) % 3 != 0)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
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