#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool has_bottleneck(vector<vector<vector<pair<int, int>>>> &last) {
  int n = last.size();
  int m = last[0].size();
  vector<set<pair<int, int>>> checkpoints(n + m - 1);
  vector<vector<bool>> visited(n, vector<bool>(m));
  checkpoints[n + m - 2].insert(make_pair(n - 1, m - 1));
  for (int i = n + m - 2; i > 1; --i) {
    for (const auto &p : checkpoints[i]) {
      for (const auto &q : last[p.first][p.second]) {
        checkpoints[i - 1].insert(q);
      }
    }
    if (checkpoints[i - 1].size() == 1)
      return true;
  }
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> mat(n);
  for (int i = 0; i < n; ++i)
    cin >> mat[i];
  vector<vector<int>> f(n, vector<int>(m));
  vector<vector<vector<pair<int, int>>>> last(
      n, vector<vector<pair<int, int>>>(m));
  f[0][0] = 1;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] != '#') {
        if (i >= 1 && f[i - 1][j] > 0) {
          f[i][j]++;
          last[i][j].emplace_back(make_pair(i - 1, j));
        }
        if (j >= 1 && f[i][j - 1] > 0) {
          f[i][j]++;
          last[i][j].emplace_back(make_pair(i, j - 1));
        }
      }
    }

  if (f[n - 1][m - 1] == 0) {
    cout << 0;
  } else {
    if (n == 1 || m == 1 || has_bottleneck(last)) {
      cout << 1;
    } else {
      cout << 2;
    }
  }
}