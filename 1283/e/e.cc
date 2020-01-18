#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
public:
  void solve() {
    int n;
    cin >> n;
    vector<int> x(n + 2);
    for (int i = 0; i < n; ++i) {
      int xi;
      scanf("%d", &xi);
      x[xi]++;
    }
    int hi = 0;
    vector<int> y(x);
    for (int i = 0; i <= n + 1; ++i) {
      if (y[i] == 0) {
        if (i <= n && y[i + 1] > 0) {
          y[i]++;
          y[i + 1]--;
        }
      }
      if (i <= n && y[i] > 1) {
        y[i]--;
        y[i + 1]++;
      }
      hi += y[i] > 0;
    }

    vector<int> f(n + 1);
    for (int i = 1; i <= n; ++i) {
      f[i] = f[i - 1] + (x[i] > 0);
      if (i >= 2)
        f[i] = min(f[i], f[i - 2] + (x[i] + x[i - 1] > 0));
      if (i >= 3)
        f[i] = min(f[i], f[i - 3] + (x[i] + x[i - 1] + x[i - 2] > 0));
    }

    cout << f[n] << " " << hi;
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}