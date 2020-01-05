#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const ll modulo = 1e9 + 7;

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> fib(max(n, m) + 1);
  fib[1] = 1;
  fib[2] = 2;
  for (int i = 3; i <= max(n, m); ++i)
    fib[i] = (fib[i - 1] + fib[i - 2]) % modulo;
  ll ans = (fib[n] + fib[m] - 1 + modulo) * 2 % modulo;
  cout << ans;
}