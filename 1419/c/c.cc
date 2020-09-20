#include <cstdio>
#include <iostream>

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
    int n, x;
    read(n), read(x);
    int delta = 0;
    int same = 0;
    for (int i = 0; i < n; ++i) {
      int a;
      read(a);
      delta += a - x;
      same += a == x;
    }
    if (same == n) {
      printf("0\n");
      return;
    }
    if (same >= 1 || delta == 0)
      printf("1\n");
    else
      printf("2\n");
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