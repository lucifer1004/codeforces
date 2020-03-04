#include <cstdio>
#include <iostream>

using namespace std;

class Solution {

public:
  void solve() {
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    int ansa = -1, ansb = -1;
    for (int i = 0; i < n; ++i) {
      int a;
      scanf("%d", &a);
      if (ansa == -1 && a % p != 0)
        ansa = i;
    }
    for (int i = 0; i < m; ++i) {
      int b;
      scanf("%d", &b);
      if (ansb == -1 && b % p != 0)
        ansb = i;
    }
    printf("%d", ansa + ansb);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}