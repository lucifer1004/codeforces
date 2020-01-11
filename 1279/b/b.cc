#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

void solve() {
  ll n, s;
  cin >> n >> s;

  vector<ll> skip(n + 1), skip_num(n + 1), sum(n + 1);
  for (int i = 1; i <= n; ++i) {
    ll a;
    cin >> a;
    sum[i] = sum[i - 1] + a;
    if (sum[i - 1] <= skip[i - 1] + a) {
      skip[i] = sum[i - 1];
      skip_num[i] = i;
    } else {
      skip[i] = skip[i - 1] + a;
      skip_num[i] = skip_num[i - 1];
    }
  }

  if (sum[n] <= s) {
    cout << 0 << endl;
    return;
  } else
    for (int i = 1; i <= n; ++i) {
      if (skip[i] > s) {
        cout << skip_num[i - 1] << endl;
        return;
      }
    }
  cout << skip_num[n] << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}