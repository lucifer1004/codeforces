#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b, int c) { return min(a, min(b, c)); }
int min(int a, int b, int c, int d) { return min(min(a, b), min(c, d)); }
int max(int a, int b, int c, int d) { return max(max(a, b), max(c, d)); }

int st[505][505][11][11];
int lg[505];

class Solution {
public:
  void solve() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    vector<string> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    vector<vector<int>> r(n + 2, vector<int>(m + 2));
    vector<vector<int>> g(r), y(r), b(r), logo(r);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        if (a[i - 1][j - 1] == 'R')
          r[i][j] = min(r[i - 1][j], r[i][j - 1], r[i - 1][j - 1]) + 1;

    for (int i = 1; i <= n; ++i)
      for (int j = m; j >= 1; --j)
        if (a[i - 1][j - 1] == 'G')
          g[i][j] = min(g[i - 1][j], g[i][j + 1], g[i - 1][j + 1]) + 1;

    for (int i = n; i >= 1; --i)
      for (int j = 1; j <= m; ++j)
        if (a[i - 1][j - 1] == 'Y')
          y[i][j] = min(y[i + 1][j], y[i][j - 1], y[i + 1][j - 1]) + 1;

    for (int i = n; i >= 1; --i)
      for (int j = m; j >= 1; --j)
        if (a[i - 1][j - 1] == 'B')
          b[i][j] = min(b[i + 1][j], b[i][j + 1], b[i + 1][j + 1]) + 1;

    for (int i = 1; i < n; ++i)
      for (int j = 1; j < m; ++j)
        logo[i][j] = min(r[i][j], g[i][j + 1], y[i + 1][j], b[i + 1][j + 1]);

    memset(st, 0, sizeof(st));
    for (int ys = 1; ys <= lg[n] + 1; ++ys)
      for (int xs = 1; xs <= lg[m] + 1; ++xs)
        for (int i = 1; i <= n; ++i)
          for (int j = 1; j <= m; ++j) {
            int &curr = st[i][j][xs][ys];
            if (xs == 1 && ys == 1)
              curr = logo[i][j];
            else {
              curr = max(st[i][j][xs - 1][ys], st[i][j][xs][ys - 1]);
              int rstart = j, bstart = i;
              int xlast = max(1, xs - 1);
              int ylast = max(1, ys - 1);
              if (xs >= 2)
                rstart = min(j + (1 << (xs - 2)), m);
              if (ys >= 2)
                bstart = min(i + (1 << (ys - 2)), n);
              curr = max(curr, st[bstart][rstart][xlast][ylast]);
            }
          }

    for (int i = 0; i < q; ++i) {
      int r1, c1, r2, c2;
      scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
      int max_size = min(r2 - r1 + 1, c2 - c1 + 1) / 2;
      int lo = 0, hi = max_size;
      int ans = 0;
      while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int lmin = max(1, c1 + mid - 1);
        int tmin = max(1, r1 + mid - 1);
        int rmax = c2 - mid;
        int bmax = r2 - mid;
        int dx = lg[rmax - lmin + 1];
        int dy = lg[bmax - tmin + 1];
        int result =
            max(st[tmin][lmin][dx + 1][dy + 1],
                st[bmax - (1 << dy) + 1][lmin][dx + 1][dy + 1],
                st[tmin][rmax - (1 << dx) + 1][dx + 1][dy + 1],
                st[bmax - (1 << dy) + 1][rmax - (1 << dx) + 1][dx + 1][dy + 1]);
        result = min(result, mid);
        ans = max(ans, result);
        if (result >= mid)
          lo = mid + 1;
        else
          hi = mid - 1;
      }
      printf("%d\n", 4 * ans * ans);
    }
  }
};

int main() {
  for (int i = 1; i <= 500; ++i)
    lg[i] = log2(i);
  Solution solution = Solution();
  solution.solve();
}