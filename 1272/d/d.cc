#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
      scanf("%d", &a[i]);
    vector<int> skip(n + 1), noskip(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] > a[i - 1]) {
        noskip[i] = noskip[i - 1] + 1;
      } else {
        noskip[i] = 1;
      }

      if (a[i] > a[i - 1]) {
        skip[i] = skip[i - 1] + 1;
      }
      if (i >= 2 && a[i] > a[i - 2]) {
        skip[i] = max(skip[i], noskip[i - 2] + 1);
      }

      ans = max(ans, skip[i]);
      ans = max(ans, noskip[i]);
    }
    printf("%d", ans);
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}