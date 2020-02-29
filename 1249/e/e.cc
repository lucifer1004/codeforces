#include <cstdio>
#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f

using namespace std;

class Solution {
public:
  void solve() {
    int n, c;
    scanf("%d%d", &n, &c);
    vector<int> a(n - 1), b(n - 1);
    for (int i = 0; i < n - 1; ++i)
      scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; ++i)
      scanf("%d", &b[i]);
    int foot = 0, elevator = c;
    printf("0 ");
    for (int i = 0; i < n - 1; ++i) {
      int nf = min(foot, elevator) + a[i];
      int ne = min(foot + c, elevator) + b[i];
      printf("%d ", min(nf, ne));
      foot = nf, elevator = ne;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}