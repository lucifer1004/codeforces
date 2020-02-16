#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

class Solution {
public:
  void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    int t, h, l;
    int lo = m, hi = m, lastt = 0;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      scanf("%d%d%d", &t, &l, &h);
      if (ok) {
        int delta = t - lastt;
        lastt = t;
        lo -= delta, hi += delta;
        if (lo > h || hi < l)
          ok = false;
        lo = max(lo, l);
        hi = min(hi, h);
      }
    }
    if (ok)
      printf("YES\n");
    else
      printf("NO\n");
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