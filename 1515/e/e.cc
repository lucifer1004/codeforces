#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define N 405

using namespace std;

template <typename T> void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-')
      sig = -1;
  for (; isdigit(c); c = getchar())
    x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

// f[len][after]: `n-1` goes after `n-2`, length is `len`, `after` numbers
// after `n-1`.
// g[len][before]: `n-1` goes before `n-2` or no `n-2`, length is `len`,
// `before` numbers before `n-1`.
// h[n][len]: maximum is `n` and length is `len`.

int h[N][N];

class Solution {
public:
  void solve() {
    int n, m;
    read(n), read(m);

    vector<vector<int>> f(n + 1, vector<int>(n + 1)),
        g(n + 1, vector<int>(n + 1));
    memset(h, 0, sizeof(h));

    f[2][0] = g[2][0] = h[1][1] = 1;
    h[2][2] = 2;

    for (int i = 3; i <= n; ++i) {
      vector<vector<int>> df(n + 1, vector<int>(n + 1)),
          dg(n + 1, vector<int>(n + 1));

      // f -> f
      for (int len = 1; len <= i - 1; ++len)
        for (int after = 0; after < len; ++after) {
          if (f[len][after]) {
            df[len + 1][0] = (df[len + 1][0] + f[len][after]) % m;
            df[len + 1][after + 1] =
                (df[len + 1][after + 1] + m - f[len][after]) % m;
          }
        }

      // g -> g, g -> f
      for (int len = 1; len <= i - 1; ++len)
        for (int before = 0; before < len; ++before) {
          if (g[len][before]) {
            dg[len + 1][0] = (dg[len + 1][0] + g[len][before]) % m;
            dg[len + 1][before + 1] =
                (dg[len + 1][before + 1] + m - g[len][before]) % m;

            int after = len - before - 1;
            df[len + 1][0] = (df[len + 1][0] + g[len][before]) % m;
            df[len + 1][after + 1] =
                (df[len + 1][after + 1] + m - g[len][before]) % m;
          }
        }

      for (int len = 1; len <= i; ++len)
        for (int k = 1; k < len; ++k) {
          df[len][k] = (df[len][k] + df[len][k - 1]) % m;
          dg[len][k] = (dg[len][k] + dg[len][k - 1]) % m;
        }

      // h[i - 2] -> g
      for (int len = 1; len <= i - 2; ++len) {
        if (h[i - 2][len]) {
          for (int before = 0; before <= len; ++before)
            dg[len + 1][before] = (dg[len + 1][before] + h[i - 2][len]) % m;
        }
      }

      for (int len = 1; len <= i; ++len)
        for (int k = 0; k < len; ++k)
          h[i][len] = ((h[i][len] + df[len][k]) % m + dg[len][k]) % m;

      f = move(df);
      g = move(dg);
    }

    int ans = 0;

    for (int j = 1; j <= n; ++j)
      ans = (ans + h[n][j]) % m;

    printf("%d\n", ans);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}