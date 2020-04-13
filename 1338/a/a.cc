#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
public:
  void solve() {
    int n;
    scanf("%d", &n);
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
      scanf("%lld", &a[i]);
    int ans = 0;
    for (int i = 1; i < n; ++i) {
      if (a[i] < a[i - 1]) {
        ans = max(ans, int(1 + log2(a[i - 1] - a[i])));
        a[i] = a[i - 1];
      }
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