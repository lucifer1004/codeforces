#include <iostream>
#include <vector>

const int dx[4] = {0, 1, 0, 1};
const int dy[4] = {0, 0, 1, 1};

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  std::vector<std::vector<int>> b(n, std::vector<int>(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      std::cin >> a[i][j];
  std::vector<std::pair<int, int>> ans;
  for (int i = 0; i < n - 1; ++i)
    for (int j = 0; j < m - 1; ++j) {
      bool need = true;
      for (int k = 0; k < 4; ++k) {
        if (a[i + dy[k]][j + dx[k]] == 0) {
          need = false;
          break;
        }
      }
      if (need) {
        ans.emplace_back(i + 1, j + 1);
        for (int k = 0; k < 4; ++k)
          b[i + dy[k]][j + dx[k]] = 1;
      }
    }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (a[i][j] != b[i][j]) {
        std::cout << -1;
        return 0;
      }
  std::cout << ans.size() << std::endl;
  for (auto p : ans)
    std::cout << p.first << " " << p.second << std::endl;
}