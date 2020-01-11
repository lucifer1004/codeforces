#include <algorithm>
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

struct Segment {
  int l, r;
};

class Solution {
 public:
  void solve() {
    int n;
    cin >> n;
    vector<Segment> s;
    for (int i = 0; i < n; ++i) {
      int l, r;
      cin >> l >> r;
      s.push_back({l, r});
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