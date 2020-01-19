#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
const int upper = 1e9;

class Solution {
public:
  void solve() {
    int n, sx, sy;
    cin >> n >> sx >> sy;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i)
      scanf("%d%d", &x[i], &y[i]);
    int ans = -1, xi = 0, yi = 0;
    for (int k = 0; k < 4; ++k) {
      int px = sx + dx[k];
      int py = sy + dy[k];
      if (px < 0 || px > upper || py < 0 || py > upper)
        continue;
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        int ds = abs(x[i] - sx) + abs(y[i] - sy);
        int dp = abs(x[i] - px) + abs(y[i] - py);
        if (dp + 1 == ds)
          cnt++;
      }
      if (cnt > ans) {
        ans = cnt;
        xi = px;
        yi = py;
      }
    }
    cout << ans << endl;
    cout << xi << " " << yi << endl;
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}