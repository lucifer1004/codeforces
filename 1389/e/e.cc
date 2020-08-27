#include <cstdio>
#include <iostream>

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

int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }

class Solution {
public:
  void solve() {
    int m, d, w;
    read(m), read(d), read(w);
    if (m == 1 || d == 1) {
      printf("0\n");
      return;
    }
    int g = gcd(d - 1, w);
    int k = w / g;
    int t = min(m, d);
    int h = (t - 1) / k;
    ll ans = ((ll)2 * t - (ll)(h + 1) * k) * h / 2;
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