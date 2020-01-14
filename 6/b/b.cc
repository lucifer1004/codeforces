#include <iostream>
#include <set>
#include <vector>

using namespace std;
typedef long long ll;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

class Solution {
 public:
  void solve() {
    int n, m;
    cin >> n >> m;
    char c;
    cin >> c;
    vector<string> layout(n);
    for (int i = 0; i < n; ++i) cin >> layout[i];
    set<char> deputies;

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        if (layout[i][j] == c) {
          for (int k = 0; k < 4; ++k) {
            int ni = i + dy[k];
            int nj = j + dx[k];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m ||
                layout[ni][nj] == '.' || layout[ni][nj] == c)
              continue;
            deputies.insert(layout[ni][nj]);
          }
        }
      }
    cout << deputies.size();
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}