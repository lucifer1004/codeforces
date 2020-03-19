#include <cstdio>
#include <map>
#include <vector>

typedef long long ll;
const ll MOD = 998244353;

int main() {
  int n;
  scanf("%d", &n);
  std::map<int, int> a, b;
  std::map<std::pair<int, int>, int> c;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[x]++, b[y]++, c[std::make_pair(x, y)]++;
  }
  std::vector<ll> fac = {1};
  for (int i = 1; i <= n; ++i)
    fac.emplace_back(fac[i - 1] * i % MOD);
  ll cnta = 1, cntb = 1, cntc = 1;
  for (auto p : a)
    cnta = cnta * fac[p.second] % MOD;
  for (auto p : b)
    cntb = cntb * fac[p.second] % MOD;
  int rmax = 0;
  for (auto p : c) {
    if (p.first.second < rmax) {
      cntc = 0;
      break;
    }
    cntc = cntc * fac[p.second] % MOD;
    rmax = std::max(rmax, p.first.second);
  }
  ll ans = ((fac[n] - (cnta + cntb - cntc)) % MOD + MOD) % MOD;
  printf("%lld", ans);
}