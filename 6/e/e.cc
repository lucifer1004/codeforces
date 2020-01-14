#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
 public:
  void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];
    map<int, int> s;
    int ans = 0;
    vector<pair<int, int>> results;

    int l = 0, r = 0;
    while (r < n) {
      s[h[r]]++;
      int lowest = s.begin()->first;
      int highest = prev(s.end())->first;
      while (highest - lowest > k) {
        s[h[l]]--;
        if (s[h[l]] == 0) s.erase(h[l]);
        l++;
        lowest = s.begin()->first;
        highest = prev(s.end())->first;
      }
      if (r - l + 1 > ans) {
        results.clear();
        ans = r - l + 1;
      }
      if (r - l + 1 == ans) {
        results.push_back({l + 1, r + 1});
      }
      r++;
    }
    cout << ans << " " << results.size() << endl;
    for (auto result : results)
      cout << result.first << " " << result.second << endl;
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}