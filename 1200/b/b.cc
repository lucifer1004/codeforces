#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
 public:
  void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];
    for (int i = 0; i < n - 1; ++i) {
      if (h[i] + m < h[i + 1] - k) {
        cout << "NO" << endl;
        return;
      }
      m -= max(0, h[i + 1] - k) - h[i];
    }
    cout << "YES" << endl;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}