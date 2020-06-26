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
  int n;
  int solve(vector<int> &a, vector<int> &b, int e) {
    for (int i = 0; i < n - 1; ++i) {
      e = min(b[i], e + b[i] - a[i]);
      if (e < 0)
        return -1;
    }
    return e;
  }

public:
  void solve() {
    read(n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
      read(a[i]);
    for (int i = 0; i < n; ++i)
      read(b[i]);
    int x = solve(a, b, b[n - 1]);
    if (x == -1) {
      printf("NO\n");
      return;
    }
    int l = 0, r = b[n - 1] - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      int y = solve(a, b, mid);
      if (y < x)
        l = mid + 1;
      else
        r = mid - 1;
    }
    if (b[n - 1] - l + x >= a[n - 1])
      printf("YES\n");
    else
      printf("NO\n");
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