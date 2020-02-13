#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void solve() {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> seg(n);
    for (int i = 0; i < n; ++i)
      scanf("%d%d", &seg[i].first, &seg[i].second);
    sort(seg.begin(), seg.end());
    int l = seg[0].first, r = seg[0].second;
    vector<pair<int, int>> intersection;
    for (int i = 1; i < n; ++i) {
      if (seg[i].first > r) {
        intersection.emplace_back(l, r);
        l = seg[i].first;
        r = seg[i].second;
      } else {
        l = seg[i].first;
        r = min(r, seg[i].second);
      }
    }
    intersection.emplace_back(l, r);
    int ans;
    if (intersection.size() == 1)
      ans = 0;
    else
      ans = intersection.back().first - intersection.front().second;
    printf("%d\n", ans);
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