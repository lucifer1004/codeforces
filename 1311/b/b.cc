#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n), p(m);
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i)
      scanf("%d", &p[i]);
    sort(p.begin(), p.end());
    vector<pair<int, int>> seg;
    int left = p[0], right = p[0] + 1;
    for (int i = 1; i < m; ++i) {
      if (p[i] == right)
        right++;
      else {
        seg.emplace_back(left - 1, right);
        left = p[i];
        right = p[i] + 1;
      }
    }
    seg.emplace_back(left - 1, right);
    for (pair<int, int> s : seg)
      sort(a.begin() + s.first, a.begin() + s.second);
    for (int i = 1; i < n; ++i)
      if (a[i] < a[i - 1]) {
        printf("NO\n");
        return;
      }
    printf("YES\n");
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