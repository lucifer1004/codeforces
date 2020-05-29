#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> d(n);
  ll ans = 0;
  bool early = false;
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
    if (d[i] >= x) {
      ans = max(ans, d[i] * x - x * (x - 1) / 2);
      early = true;
    }
  }
  if (early) {
    cout << ans;
    exit(0);
  }
  for (int i = 0; i < n; ++i)
    d.emplace_back(d[i]);
  vector<ll> sd = {0}, sh = {0};
  for (int i = 0; i < n * 2; ++i) {
    sd.emplace_back(sd.back() + d[i]);
    sh.emplace_back(sh.back() + d[i] * (d[i] + 1) / 2);
  }
  for (int i = 0; i < n; ++i) {
    int l = i + 1, r = n * 2 - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      ll tot = sd[mid + 1] - sd[i + 1];
      if (tot < x - d[i])
        l = mid + 1;
      else
        r = mid - 1;
    }
    ll remain = x - (sd[r + 1] - sd[i + 1]);
    ll hugs = sh[r + 1] - sh[i + 1];
    if (d[i] >= remain)
      hugs += remain * d[i] - remain * (remain - 1) / 2;
    else {
      ll right = min(remain, d[r + 1]);
      hugs += right * (right + 1) / 2;
      ll left = remain - right;
      hugs += left * d[i] - left * (left - 1) / 2;
    }
    ans = max(ans, hugs);
  }
  cout << ans;
}