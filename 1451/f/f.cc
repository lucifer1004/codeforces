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
    vector<int> x(n + m - 1);
    int aij;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        read(aij);
        x[i + j] ^= aij;
      }
    for (int i = 0; i < n + m - 1; ++i)
      if (x[i] != 0) {
        printf("Ashish\n");
        return;
      }
    printf("Jeel\n");
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