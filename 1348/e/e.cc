#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
public:
  void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<ll> f(k, -1);
    vector<int> g(k);
    f[0] = 0;
    for (int i = 0; i < n; ++i) {
      int a, b;
      scanf("%d%d", &a, &b);
      vector<ll> nf(k, -1);
      vector<int> ng(k);
      for (int red = 0; red < min(a + 1, k); ++red) {
        int red_remain = a - red;
        int same = (red_remain + b) / k;
        int rest = (red_remain + b) % k;
        int blue_remain = min(b, rest);
        for (int j = 0; j < k; ++j) {
          if (f[j] == -1)
            continue;
          int nxt = (j + red) % k;
          int blue = g[j] + blue_remain;
          ll curr = f[j] + same + (j + red) / k + blue / k;
          if (curr > nf[nxt] || (curr == nf[nxt] && blue % k > ng[nxt])) {
            nf[nxt] = curr;
            ng[nxt] = blue % k;
          }
        }
      }
      swap(f, nf), swap(g, ng);
    }
    printf("%lld", *max_element(f.begin(), f.end()));
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}