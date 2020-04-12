#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  int t;
  scanf("%d", &t);
  string out;
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i)
      scanf("%lld%lld", &a[i], &b[i]);
    vector<ll> rest(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i)
      sum += rest[i] = max(0ll, a[i] - b[(i - 1 + n) % n]);
    ll ans = LLONG_MAX;
    for (int i = 0; i < n; ++i)
      ans = min(ans, sum - rest[i] + a[i]);
    out += to_string(ans) + "\n";
  }
  printf("%s", out.c_str());
}