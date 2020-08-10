#include <cstdio>
#include <iostream>
#define MOD 1000000007

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
    int n;
    read(n);
    ll fac = 1;
    for (int i = 1; i <= n; ++i)
      fac = fac * i % MOD;
    ll two = 1;
    for (int i = 1; i <= n - 1; ++i)
      two = two * 2 % MOD;
    ll ans = (fac - two + MOD) % MOD;
    printf("%lld", ans);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}