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
    vector<int> p(n << 1);
    for (int i = 0; i < (n << 1); ++i)
      read(p[i]);
    vector<int> goods;
    int last = n << 1;
    while (last) {
      int hi = 0, idx = -1;
      for (int i = 1; i <= last; ++i) {
        if (p[i - 1] > hi) {
          hi = p[i - 1];
          idx = i;
        }
      }
      goods.emplace_back(last - idx + 1);
      last = idx - 1;
    }
    vector<bool> dp(n + 1);
    dp[0] = true;
    for (int i : goods) {
      for (int j = n; j >= i; --j)
        dp[j] = dp[j] || dp[j - i];
    }
    printf(dp[n] ? "YES\n" : "NO\n");
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