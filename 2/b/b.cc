/*
 * The integers are non-negative, so there can be 0s！
 */

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

pair<int, string> min_trace(vector<vector<int>>& arr) {
  int n = arr.size();
  vector<vector<int>> cnt(n, vector<int>(n, INT_MAX));
  vector<string> trace(n, string(n, 'D'));
  cnt[0][0] = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      if (i > 0 && cnt[i - 1][j] < cnt[i][j]) {
        cnt[i][j] = cnt[i - 1][j];
        trace[i][j] = 'D';
      }
      if (j > 0 && cnt[i][j - 1] < cnt[i][j]) {
        cnt[i][j] = cnt[i][j - 1];
        trace[i][j] = 'R';
      }
      cnt[i][j] += arr[i][j];
    }

  string path(n * 2 - 2, ' ');
  int ci = n - 1, cj = n - 1;
  for (int i = 2 * n - 3; i >= 0; --i) {
    path[i] = trace[ci][cj];
    if (path[i] == 'D')
      ci--;
    else
      cj--;
  }

  return make_pair(cnt[n - 1][n - 1], path);
}

int main() {
  int n;
  cin >> n;
  int zi = -1, zj = -1;
  vector<vector<int>> two(n, vector<int>(n)), five(n, vector<int>(n));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      int d;
      scanf("%d", &d);
      if (d == 0) {
        zi = i;
        zj = j;
        two[i][j] = 1e9;
        five[i][j] = 1e9;
        continue;
      }
      while (d % 5 == 0) {
        five[i][j]++;
        d /= 5;
      }
      while (!(d & 1)) {
        two[i][j]++;
        d >>= 1;
      }
    }

  const auto& [go_two, two_path] = min_trace(two);
  const auto& [go_five, five_path] = min_trace(five);
  int ans = min(go_two, go_five);
  if (ans > 1 && zi >= 0) {
    cout << 1 << endl;
    for (int i = 0; i < zi; ++i) cout << 'D';
    for (int j = 0; j < zj; ++j) cout << 'R';
    for (int i = zi + 1; i < n; ++i) cout << 'D';
    for (int j = zj + 1; j < n; ++j) cout << 'R';
    return 0;
  }
  cout << ans << endl;
  if (ans == go_two)
    cout << two_path;
  else
    cout << five_path;
}