#include <iostream>
#include <vector>
#define MOD 1000000007
#define MAXN 2000005

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<ll> f = {0}, g = {0}, h = {1};
  for (int i = 1; i < MAXN; ++i) {
    f.emplace_back((f[i - 1] + g[i - 1]) % MOD);
    g.emplace_back(h[i - 1]);
    h.emplace_back((h[i - 1] + g[i - 1] * 2) % MOD);
  }
  vector<ll> ans(MAXN);
  for (int j = 3; j < MAXN; ++j)
    ans[j] = (ans[j - 3] + g[j - 2]) % MOD;
  int t;
  read(t);
  while (t--) {
    int n;
    read(n);
    printf("%lld\n", ans[n] * 4 % MOD);
  }
}