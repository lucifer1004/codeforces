#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

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
    int n, m = 3, k = 2;
    read(n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      read(a[i]);
    sort(a.begin(), a.end());
    ll ans = 0;
    int l = 0;
    for (int r = 2; r < n; ++r) {
      while (a[r] - a[l] > k)
        l++;
      if (r - l >= m - 1) {
        int len = r - l;
        ll ways = 1;
        for (int i = len; i > len - m + 1; --i)
          ways *= i;
        for (int i = m - 1; i > 1; --i)
          ways /= i;
        ans += ways;
      }
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