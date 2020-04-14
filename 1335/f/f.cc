#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<char, int> dx = {{'L', -1}, {'R', 1}, {'U', 0}, {'D', 0}};
map<char, int> dy = {{'L', 0}, {'R', 0}, {'U', -1}, {'D', 1}};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int r, c;
    cin >> r >> c;
    vector<string> color(r), direction(r);
    for (int i = 0; i < r; ++i)
      cin >> color[i];
    for (int i = 0; i < r; ++i)
      cin >> direction[i];
    vector<vector<bool>> vis(r, vector<bool>(c));
    vector<vector<int>> pos(r, vector<int>(c, -1)),
        belong(r, vector<int>(c, -1));
    vector<vector<bool>> loops;

    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j) {
        if (vis[i][j])
          continue;
        vis[i][j] = true;
        int step = 0;
        vector<pair<int, int>> path;
        map<pair<int, int>, int> dict;
        dict[{i, j}] = step++;
        path.emplace_back(i, j);
        int ni = i + dy[direction[i][j]];
        int nj = j + dx[direction[i][j]];
        while (true) {
          pair<int, int> p = {ni, nj};
          if (vis[ni][nj]) {
            if (dict.find(p) != dict.end()) {
              int start = dict[p];
              int length = step - start;
              loops.emplace_back(vector<bool>(length));
              for (int k = 0; k < step; ++k) {
                auto [mi, mj] = path[k];
                pos[mi][mj] = (k - start) % length;
                if (pos[mi][mj] < 0)
                  pos[mi][mj] += length;
                belong[mi][mj] = loops.size() - 1;
                if (color[mi][mj] == '0')
                  loops.back()[pos[mi][mj]] = true;
              }
            } else {
              int length = loops[belong[ni][nj]].size();
              for (int k = 0; k < step; ++k) {
                auto [mi, mj] = path[k];
                pos[mi][mj] = (k - step + pos[ni][nj]) % length;
                if (pos[mi][mj] < 0)
                  pos[mi][mj] += length;
                belong[mi][mj] = belong[ni][nj];
                if (color[mi][mj] == '0')
                  loops[belong[ni][nj]][pos[mi][mj]] = true;
              }
            }
            break;
          }
          vis[ni][nj] = true;
          dict[{ni, nj}] = step++;
          path.emplace_back(ni, nj);
          int rawi = ni;
          ni += dy[direction[ni][nj]];
          nj += dx[direction[rawi][nj]];
        }
      }
    int ans = 0, black = 0;
    for (auto loop : loops) {
      ans += loop.size();
      for (bool is_black : loop)
        black += is_black;
    }
    cout << ans << " " << black << endl;
  }
}