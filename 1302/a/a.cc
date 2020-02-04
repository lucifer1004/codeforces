#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void solve() {
    int n, m;
    scanf("%d%d", &m, &n);
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        scanf("%d", &mat[i][j]);
    for (int i = 0; i < n; ++i) {
      int hi = 0, idx = -1;
      bool valid = true;
      for (int j = 0; j < m; ++j) {
        if (mat[i][j] > hi) {
          hi = mat[i][j];
          idx = j;
          valid = true;
        } else if (mat[i][j] == hi)
          valid = false;
      }

      if (valid) {
        for (int k = 0; k < n; ++k) {
          if (k == i)
            continue;
          if (mat[k][idx] <= mat[i][idx]) {
            valid = false;
            break;
          }
        }
      }

      if (valid) {
        cout << i + 1 << " " << idx + 1;
        return;
      }
    }

    cout << "0 0";
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}