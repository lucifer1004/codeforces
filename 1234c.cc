#include <iostream>
#include <vector>

using namespace std;

typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;

const bool lr[6][6]{{0, 0, 0, 0, 0, 0}, {0, 1, 0, 1, 1, 0}, {0, 1, 0, 1, 1, 0},
                    {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 1, 0, 1, 1, 0}};
const bool tb[6][6]{{1, 0, 0, 0, 1, 1}, {0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 1, 1},
                    {1, 0, 0, 0, 1, 1}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}};
const bool trans[6][6]{{1, 1, 0, 0, 0, 0}, {1, 1, 0, 0, 0, 0},
                       {0, 0, 1, 1, 1, 1}, {0, 0, 1, 1, 1, 1},
                       {0, 0, 1, 1, 1, 1}, {0, 0, 1, 1, 1, 1}};
const int start[3]{1, 3, 4};
const int finish[2]{1, 5};

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(2, vector<int>(n));
  for (int i = 0; i < 2; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < n; ++j)
      a[i][j] = s[j] - '1';
  }

  vvvb possible(2, vvb(n, vb(6)));
  for (const int &i : start)
    if (trans[a[0][0]][i])
      possible[0][0][i] = true;

  for (int i = 0; i < 6; ++i)
    for (int j = 0; j < 6; ++j)
      if (trans[a[1][0]][j] && tb[i][j] && possible[0][0][i])
        possible[1][0][j] = true;

  for (int i = 1; i < n; ++i) {
    // left to right
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 6; ++k) {
        if (!trans[a[j][i]][k])
          continue;
        for (int t = 0; t < 6; ++t) {
          if (possible[j][i - 1][t] && lr[t][k]) {
            possible[j][i][k] = true;
            break;
          }
        }
      }
    }

    vb origin(possible[1][i]);
    // up to down
    for (int k = 0; k < 6; ++k) {
      if (!trans[a[1][i]][k] || possible[1][i][k])
        continue;
      for (int t = 0; t < 6; ++t) {
        if (possible[0][i][t] && tb[t][k]) {
          possible[1][i][k] = true;
          break;
        }
      }
    }

    // down to up
    for (int k = 0; k < 6; ++k) {
      if (!trans[a[0][i]][k] || possible[0][i][k])
        continue;
      for (int t = 0; t < 6; ++t) {
        if (origin[t] && tb[k][t]) {
          possible[0][i][k] = true;
          break;
        }
      }
    }
  }

  bool ans = false;
  for (const int &i : finish) {
    ans = ans || possible[1][n - 1][i];
  }
  cout << (ans ? "YES" : "NO") << endl;
}

int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i)
    solve();
}