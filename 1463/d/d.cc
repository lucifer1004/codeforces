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
    int n;
    read(n);
    vector<bool> in(2 * n + 2);
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
      read(b[i]), in[b[i]] = true;

    // Try to use min as often as possible
    int lo = 0, r = 2 * n;
    while (in[r])
      r--;
    for (int i = n - 1; i >= 0; --i) {
      if (r > b[i]) {
        lo++;
        r--;
        while (in[r])
          r--;
      }
    }

    // Try to use max as often as possible
    int hi = 0, l = 1;
    while (in[l])
      l++;
    for (int i = 0; i < n; ++i) {
      if (l < b[i]) {
        hi++;
        l++;
        while (in[l])
          l++;
      }
    }

    printf("%d\n", lo - (n - hi) + 1);
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