#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    set<int> s(a.begin(), a.end());
    unordered_map<int, int> lookup;
    int idx = 0;
    for (int si : s)
      lookup[si] = idx++;
    vector<int> l(s.size(), n), r(s.size()), dp(s.size(), 1);
    for (int i = 0; i < n; ++i) {
      int id = lookup[a[i]];
      l[id] = min(l[id], i);
      r[id] = i;
    }
    int maxlen = 1;
    for (int i = 1; i < s.size(); ++i) {
      if (r[i - 1] < l[i])
        dp[i] = dp[i - 1] + 1;
      maxlen = max(maxlen, dp[i]);
    }
    printf("%d\n", (int)s.size() - maxlen);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  scanf("%d", &t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}