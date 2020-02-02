#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void solve() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    k = min(k, m - 1);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    vector<int> f(m);
    for (int l = 0; l <= m - 1; ++l) {
      int r = m - 1 - l;
      int left = a[l];
      int right = a[n - r - 1];
      f[l] = max(left, right);
    }
    int ans = 0;
    for (int i = 0; i <= k; ++i) {
      int curr = INT_MAX;
      int rmin = k - i;
      int lmax = m - 1 - rmin;
      for (int j = i; j <= lmax; ++j)
        curr = min(curr, f[j]);
      ans = max(ans, curr);
    }
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