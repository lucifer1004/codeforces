#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
 public:
  void solve() {
    vector<int> a(4);
    for (int i = 0; i < 4; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    if (a[0] + a[1] > a[2] || a[1] + a[2] > a[3]) {
      cout << "TRIANGLE";
    } else if (a[0] + a[1] == a[2] || a[1] + a[2] == a[3]) {
      cout << "SEGMENT";
    } else {
      cout << "IMPOSSIBLE";
    }
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}