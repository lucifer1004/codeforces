#include <cstdio>
#include <iostream>

using namespace std;

class Solution {
public:
  void solve() {
    int n, p;
    scanf("%d%d", &n, &p);
    int i = 1;
    while (true) {
      int target = n - i * p;
      if (target < i) {
        printf("-1");
        return;
      }
      int num = __builtin_popcount(target);
      if (num <= i) {
        printf("%d", i);
        return;
      }
      i++;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}