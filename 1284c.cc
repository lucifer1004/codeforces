#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> fac(n + 1);
  fac[1] = 1;
  for (int i = 2; i <= n; ++i) fac[i] = fac[i - 1] * i % m;
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    ll curr = fac[i] * (n - i + 1) % m;
    curr = curr * fac[n - i + 1] % m;
    ans = (ans + curr) % m;
  }
  cout << ans;
}

int main() { solve(); }