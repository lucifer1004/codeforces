#include <iostream>

using namespace std;
typedef long long ll;

class Solution {
public:
  void solve() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int total = 0;
    if (e > f) {
      // Type A is more expensive
      total += min(a, d) * e;
      d -= min(a, d);
      total += min(d, min(b, c)) * f;
    } else {
      // Type B is more expensive
      total += min(d, min(b, c)) * f;
      d -= min(d, min(b, c));
      total += min(a, d) * e;
    }

    cout << total;
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}