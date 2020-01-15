#include <bitset>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
 public:
  void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        scanf("%d", &a[i][j]);
      }
    vector<int> f(1 << m), s(1 << m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 1 << m; ++j) {
        bitset<8> bs(j);
        int lo = INT_MAX;
        for (int k = 0; k < m; ++k) {
          if (bs[k]) {
            lo = min(lo, a[i][k]);
          }
        }
        if (lo > f[j]) {
          f[j] = lo;
          s[j] = i;
        }
      }
    }
    int hi = -1, l = 0, r = 0;
    for (int i = 0; i < (1 << (m - 1)); ++i) {
      int res = min(f[i], f[(1 << m) - i - 1]);
      if (res > hi) {
        hi = res;
        l = s[i];
        r = s[(1 << m) - i - 1];
      }
    }
    cout << l + 1 << " " << r + 1;
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}