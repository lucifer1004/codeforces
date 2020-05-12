#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vi;
typedef vector<vi> vvi;

int n, m, q;
vi enter, color;
vvi d = {{0, -1, 0, 1}, {-1, 0, 1, 0}};

int main() {
  scanf("%d%d%d", &n, &m, &q);
  vvb a(n, vb(m));
  for (int i = 0; i < n; ++i) {
    char c;
    for (int j = 0; j < m; ++j) {
      scanf(" %c", &c);
      a[i][j] = c == '1';
    }
  }
  enter = vi(n * m, -1);
  color = vi(n * m, -1);
  bool stable = true;
  vb vis(n * m);
  queue<int> bfs;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      int idx = i * m + j;
      for (int k = 0; k < 4; ++k) {
        int ni = i + d[0][k], nj = j + d[1][k];
        if (ni < 0 || ni >= n || nj < 0 || nj >= m)
          continue;
        int nidx = ni * m + nj;
        if (a[i][j] == a[ni][nj]) {
          enter[idx] = 0;
          enter[nidx] = 0;
          color[idx] = a[i][j];
          color[nidx] = a[i][j];
          if (!vis[idx]) {
            vis[idx] = true;
            bfs.push(idx);
          }
          if (!vis[nidx]) {
            vis[nidx] = true;
            bfs.push(nidx);
          }
          stable = false;
        }
      }
    }
  while (!bfs.empty()) {
    int idx = bfs.front();
    bfs.pop();
    int i = idx / m, j = idx % m;
    for (int k = 0; k < 4; ++k) {
      int ni = i + d[0][k], nj = j + d[1][k];
      if (ni < 0 || ni >= n || nj < 0 || nj >= m)
        continue;
      int nidx = ni * m + nj;
      if (enter[nidx] != -1 || a[ni][nj] != (color[idx] + enter[idx] + 1) % 2)
        continue;
      enter[nidx] = enter[idx] + 1;
      color[nidx] = color[idx];
      bfs.push(nidx);
    }
  }

  string ans;
  while (q--) {
    int i, j;
    ll p;
    scanf("%d%d%lld", &i, &j, &p);
    int state;
    if (stable)
      state = a[i - 1][j - 1];
    else {
      int idx = (i - 1) * m + j - 1;
      if (p < enter[idx])
        state = a[i - 1][j - 1];
      else
        state = (color[idx] + p) % 2;
    }
    ans += to_string(state) + "\n";
  }
  printf("%s", ans.c_str());
}