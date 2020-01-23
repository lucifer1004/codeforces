#include <iostream>

using namespace std;
typedef long long ll;

class Solution {
public:
  void solve() {
    int n;
    cin >> n;
    int n0 = n;
    int a = 0, b = 0, c = 0;
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        if (!a) {
          a = i;
          n /= a;
        } else if (!b) {
          b = i;
          c = n0 / a / b;
          break;
        }
      }
    }
    if (a && b && c && b != c) {
      cout << "YES" << endl;
      cout << a << " " << b << " " << c << endl;
    } else {
      cout << "NO" << endl;
    }
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