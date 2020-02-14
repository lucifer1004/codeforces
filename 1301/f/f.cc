#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dc[4] = {-1, 0, 1, 0};
const int dr[4] = {0, -1, 0, 1};

class Solution {
public:
  void solve() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    vector<vector<int>> c(n, vector<int>(m));
    vector<vector<int>> s(k + 1);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        scanf("%d", &c[i][j]);
        s[c[i][j]].emplace_back(i * m + j);
      }

    vector<vector<int>> dist(k + 1, vector<int>(n * m, -1));
    for (int i = 1; i <= k; ++i) {
      queue<int> q;
      for (int j : s[i]) {
        q.push(j);
        dist[i][j] = 0;
      }
      vector<bool> used(k + 1);
      used[i] = true;
      while (!q.empty()) {
        int f = q.front();
        q.pop();
        int row = f / m, col = f % m;
        for (int j = 0; j < 4; ++j) {
          int nr = row + dr[j], nc = col + dc[j];
          int next = nr * m + nc;
          if (nr < 0 || nr >= n || nc < 0 || nc >= m || dist[i][next] != -1)
            continue;
          dist[i][next] = dist[i][f] + 1;
          q.push(next);
        }
        if (!used[c[row][col]]) {
          for (int j : s[c[row][col]]) {
            if (dist[i][j] == -1) {
              dist[i][j] = dist[i][f] + 1;
              q.push(j);
            }
          }
          used[c[row][col]] = true;
        }
      }
    }

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
      int r1, c1, r2, c2;
      scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
      r1--, c1--, r2--, c2--;
      int ans = abs(r1 - r2) + abs(c1 - c2);
      for (int i = 1; i <= k; ++i)
        ans = min(ans, dist[i][r1 * m + c1] + dist[i][r2 * m + c2] + 1);
      printf("%d\n", ans);
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}