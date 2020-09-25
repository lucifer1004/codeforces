#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
using ll = int64_t;

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
    int n, q;
    read(n), read(q);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      read(a[i]);
    a.emplace_back(0);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] > a[i + 1])
        ans += a[i] - a[i + 1];
    }
    printf("%lld\n", ans);
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