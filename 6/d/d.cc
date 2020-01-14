#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
  int n, a, b, minshot, sum;
  vector<int> h, curr, ans, lo, hi;

  void dfs(int i) {
    int lrest = h[i - 1] - a * curr[i - 1];
    if (i >= 2) lrest -= b * curr[i - 2];
    int lneed = lrest < 0 ? 0 : lrest / b + 1;
    if (i < n - 2) {
      for (int j = max(lo[i], lneed); j <= hi[i]; ++j) {
        curr[i] = j;
        sum += j;
        if (sum < minshot) dfs(i + 1);
        sum -= j;
      }
    } else {
      int mrest = h[i] - b * curr[i - 1];
      int mneed = mrest < 0 ? 0 : mrest / a + 1;
      int rneed = h[i + 1] / b + 1;
      curr[i] = max(lneed, max(mneed, rneed));
      sum += curr[i];
      if (sum < minshot) {
        minshot = sum;
        ans = curr;
      }
      sum -= curr[i];
    }
  }

 public:
  void solve() {
    cin >> n >> a >> b;
    h = vector<int>(n);
    for (int i = 0; i < n; ++i) cin >> h[i];

    lo = vector<int>(n);
    hi = vector<int>(n);
    lo[1] = h[0] / b + 1;
    lo[n - 2] = max(lo[n - 2], h[n - 1] / b + 1);
    for (int i = 1; i < n - 1; ++i) {
      int l = h[i - 1] / b + 1;
      int m = h[i] / a + 1;
      int r = h[i + 1] / b + 1;
      hi[i] = max(l, max(m, r));
    }

    ans = vector<int>(n);
    curr = vector<int>(n);
    sum = 0;
    minshot = INT_MAX;
    dfs(1);

    cout << minshot << endl;
    for (int i = 1; i < n - 1; ++i)
      for (int j = 0; j < ans[i]; ++j) {
        cout << i + 1 << " ";
      }
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}