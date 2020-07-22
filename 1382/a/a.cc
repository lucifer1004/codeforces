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
    vector<bool> vis(1001);
    for (int i = 0; i < n; ++i) {
      int x;
      read(x);
      vis[x] = true;
    }
    int ans = -1;
    for (int i = 0; i < m; ++i) {
      int x;
      read(x);
      if (vis[x])
        ans = x;
    }
    if (ans == -1)
      printf("NO\n");
    else
      printf("YES\n1 %d\n", ans);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  read(t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}