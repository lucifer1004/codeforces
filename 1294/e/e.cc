#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
public:
  void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> col(m, vector<int>(n));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        scanf("%d", &col[j][i]);
    int ans = 0;
    for (int j = 0; j < m; ++j) {
      vector<set<int>> f(n);
      for (int i = 0; i < n; ++i) {
        int div = (col[j][i] - 1) / m;
        int rem = col[j][i] % m;
        if (rem == (j + 1) % m && div < n) {
          int delta = (i - div + n) % n;
          f[delta].insert(col[j][i]);
        }
      }
      int lo = INT_MAX;
      for (int i = 0; i < n; ++i) {
        lo = min(lo, n - (int)f[i].size() + i);
      }
      ans += lo;
    }
    cout << ans;
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}