#include <cstdio>
#include <iostream>
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
    vector<int> b;
    b.reserve(n);
    int ans = 0, lo = 1e9, hi = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == -1) {
        if (i > 0 && a[i - 1] != -1) {
          lo = min(lo, a[i - 1]);
          hi = max(hi, a[i - 1]);
        }
        if (i < n - 1 && a[i + 1] != -1) {
          lo = min(lo, a[i + 1]);
          hi = max(hi, a[i + 1]);
        }
      } else {
        if (i > 0 && a[i - 1] != -1)
          ans = max(ans, abs(a[i] - a[i - 1]));
        if (i < n - 1 && a[i + 1] != -1)
          ans = max(ans, abs(a[i] - a[i + 1]));
      }
    }
    if (lo > hi)
      printf("0 0\n");
    else
      printf("%d %d\n", max(ans, (hi - lo + 1) / 2), (hi + lo) / 2);
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