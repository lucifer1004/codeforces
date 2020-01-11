#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> ans(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i % 2 == 0)
        ans[i][j] = i * n + j + 1;
      else
        ans[i][j] = (i + 1) * n - j;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cout << ans[j][i] << " ";
    cout << endl;
  }
}