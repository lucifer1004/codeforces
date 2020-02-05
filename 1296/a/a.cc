#include <cstdio>
#include <iostream>

using namespace std;

class Solution {
public:
  void solve() {
    int n;
    scanf("%d", &n);
    int even = 0, odd = 0;
    for (int i = 0; i < n; ++i) {
      int t;
      scanf("%d", &t);
      odd += t % 2;
    }
    even = n - odd;
    if (n % 2 == 0) {
      if (even > 0 && odd > 0)
        printf("YES\n");
      else
        printf("NO\n");
    } else {
      if (odd > 0)
        printf("YES\n");
      else
        printf("NO\n");
    }
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