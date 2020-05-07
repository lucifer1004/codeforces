#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

class Solution {
public:
  void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> mat(n);
    for (int i = 0; i < n; ++i)
      cin >> mat[i];
    bool valid = true, has_black = false;
    set<int> blackrow, blackcol;
    // Check row validity
    for (int i = 0; i < n; ++i) {
      int start = 0;
      bool in = false;
      for (int j = 0; j < m; ++j) {
        if (mat[i][j] == '#') {
          blackrow.insert(i);
          blackcol.insert(j);
          if (!in) {
            in = true;
            start++;
          }
        } else
          in = false;
      }
      if (start > 1) {
        valid = false;
        break;
      }
    }
    if ((blackrow.size() == n) ^ (blackcol.size() == m))
      valid = false;
    if (valid)
      for (int i = 0; i < m; ++i) {
        int start = 0;
        bool in = false;
        for (int j = 0; j < n; ++j) {
          if (!in && mat[j][i] == '#') {
            in = true;
            start++;
          } else if (in && mat[j][i] == '.')
            in = false;
        }
        if (start > 1) {
          valid = false;
          break;
        }
      }
    if (!valid) {
      cout << -1;
      return;
    }
    vector<vector<bool>> vis(n, vector<bool>(m));
    queue<pair<int, int>> q;
    int ans = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        if (mat[i][j] == '.' || vis[i][j])
          continue;
        ans++;
        q.push({i, j});
        while (!q.empty()) {
          auto [ci, cj] = q.front();
          q.pop();
          for (int k = 0; k < 4; ++k) {
            int ni = ci + dy[k], nj = cj + dx[k];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || vis[ni][nj] ||
                mat[ni][nj] == '.')
              continue;
            vis[ni][nj] = true;
            q.push({ni, nj});
          }
        }
      }
    cout << ans;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}