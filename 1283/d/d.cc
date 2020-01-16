#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long ll;
const int dx[2] = {-1, 1};

class Solution {
 public:
  void solve() {
    int n, m;
    cin >> n >> m;
    unordered_set<int> visited;
    visited.reserve(1 << 20);
    visited.max_load_factor(0.25);
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      visited.insert(x);
      q.push(make_pair(x, 0));
    };

    ll ans = 0;
    vector<int> y;
    while (!q.empty()) {
      pair<int, int> f = q.front();
      q.pop();
      if (f.second >= 1) {
        ans += (ll)f.second;
        y.push_back(f.first);
        if (y.size() == m) break;
      }
      for (int i = 0; i < 2; ++i) {
        int nx = f.first + dx[i];
        if (visited.find(nx) == visited.end()) {
          visited.insert(nx);
          q.push(make_pair(nx, f.second + 1));
        }
      }
    }

    cout << ans << endl;
    for (int yi : y) cout << yi << " ";

    return;
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}