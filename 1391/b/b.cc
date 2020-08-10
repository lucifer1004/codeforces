#include <cstdio>
#include <iostream>
#include <vector>

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

class Solution {
public:
  void solve() {
    int n, m;
    read(n), read(m);
    vector<string> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n - 1; ++i)
      ans += a[i][m - 1] != 'D';
    for (int j = 0; j < m - 1; ++j)
      ans += a[n - 1][j] != 'R';
    printf("%d\n", ans);
  }
};

int main() {
  int t;
  read(t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}