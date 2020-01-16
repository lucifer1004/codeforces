#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
  int ans;

 public:
  void solve() {
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) cin >> l[i];
    for (int i = 0; i < n; ++i) cin >> r[n - i - 1];
    unordered_map<int, int> dict;
    int ones = 0, twos = 0;
    dict[0] = 0;
    for (int i = 0; i < n; ++i) {
      ones += r[i] == 1;
      twos += r[i] == 2;
      dict[ones - twos] = i + 1;
    }
    int ans = dict[0];
    ones = 0, twos = 0;
    for (int i = 0; i < n; ++i) {
      ones += l[i] == 1;
      twos += l[i] == 2;
      if (dict.find(twos - ones) != dict.end()) {
        ans = max(ans, dict[twos - ones] + i + 1);
      }
    }

    cout << 2 * n - ans << endl;
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