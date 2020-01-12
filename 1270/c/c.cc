#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  ll sum = 0, xsu = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
    xsu ^= a[i];
  }

  ll ans1 = xsu;
  ll ans2 = xsu + sum;
  cout << 2 << endl;
  cout << ans1 << " " << ans2 << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}