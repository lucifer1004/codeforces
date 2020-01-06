#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

void solve() {
  int n, m;
  cin >> n;
  ll a, b, oa = 0, ob = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a);
    oa += a % 2;
  }
  ll ea = n - oa;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    scanf("%lld", &b);
    ob += b % 2;
  }
  ll eb = m - ob;
  ll ans = oa * ob + ea * eb;
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i)
    solve();
}