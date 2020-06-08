#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<string> mat(n);
    for (int i = 0; i < n; ++i)
      cin >> mat[i];
    bool solvable = true;
    int good = 0;
    auto valid = [&](int i, int j) {
      return i >= 0 && i < n && j >= 0 && j < m;
    };
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        if (mat[i][j] == 'B') {
          for (int k = 0; k < 4; ++k) {
            int ci = i + dy[k], cj = j + dx[k];
            if (!valid(ci, cj))
              continue;
            if (mat[ci][cj] == 'G')
              solvable = false;
            if (mat[ci][cj] == '.')
              mat[ci][cj] = '#';
          }
        }
        if (mat[i][j] == 'G')
          good++;
      }
    if (good)
      for (int k = 0; k < 4; ++k) {
        int ci = n - 1 + dy[k], cj = m - 1 + dx[k];
        if (valid(ci, cj) && mat[ci][cj] == 'B')
          solvable = false;
      }
    if (!solvable) {
      cout << "No" << endl;
      continue;
    }
    queue<pair<int, int>> q;
    q.push({n - 1, m - 1});
    int visited = 0;
    vector<vector<bool>> vis(n, vector<bool>(m));
    while (!q.empty()) {
      auto [i, j] = q.front();
      if (mat[i][j] == 'G')
        visited++;
      q.pop();
      for (int k = 0; k < 4; ++k) {
        int ci = i + dy[k], cj = j + dx[k];
        if (!valid(ci, cj) || mat[ci][cj] == '#' || vis[ci][cj])
          continue;
        vis[ci][cj] = true;
        q.push({ci, cj});
      }
    }
    cout << (visited == good ? "Yes" : "No") << endl;
  }
}