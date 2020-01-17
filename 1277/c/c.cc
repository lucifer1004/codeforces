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
 public:
  void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> ans;
    for (int i = 0; i < n - 2;) {
      string c = s.substr(i, 3);
      if (c == "one") {
        ans.push_back(i + 2);
        i += 3;
      } else if (c == "two") {
        if (i + 4 < n && s.substr(i + 3, 2) == "ne") {
          ans.push_back(i + 3);
          i += 5;
        } else {
          ans.push_back(i + 2);
          i += 3;
        }
      } else
        i++;
    }
    cout << ans.size() << endl;
    for (int i : ans) cout << i << " ";
    cout << endl;
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