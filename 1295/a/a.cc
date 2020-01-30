#include <cstdio>
#include <iostream>

using namespace std;

class Solution {
public:
  void solve() {
    int n;
    scanf("%d", &n);
    if (n % 2 == 1) {
      printf("7");
      n -= 3;
    }
    while (n > 0) {
      printf("1");
      n -= 2;
    }
    printf("\n");
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