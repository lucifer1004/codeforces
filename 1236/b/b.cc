#include <iostream>

using namespace std;
typedef long long ll;

const ll modulo = 1e9 + 7;

ll fast_exp(ll x, ll y) {
  if (y == 0) return 1;
  ll half = fast_exp(x, y / 2);
  ll ans = half * half % modulo;
  if (y % 2) ans = ans * x % modulo;
  return ans;
}

int main() {
  ll n, m;
  cin >> n >> m;
  ll base = fast_exp(2, m);
  base = (base + modulo - 1) % modulo;
  ll ans = fast_exp(base, n);
  cout << ans;
  return 0;
}