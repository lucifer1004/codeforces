#include <cstdio>
#include <iostream>

using namespace std;

class Solution {
public:
  void solve() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    while (n >= 10) {
      ans += n - n % 10;
      n = n / 10 + n % 10;
    }
    ans += n;
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