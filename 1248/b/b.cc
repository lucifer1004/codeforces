#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%lld", &a[i]);
  sort(a.begin(), a.end());
  ll left = 0, right = 0;
  for (int i = 0; i < n / 2; ++i)
    left += a[i];
  for (int i = n / 2; i < n; ++i)
    right += a[i];
  ll ans = left * left + right * right;
  cout << ans;
}