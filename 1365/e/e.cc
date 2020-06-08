#include <algorithm>
#include <iostream>
#include <vector>
#define MAXD 62

using namespace std;
typedef long long ll;
int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  if (n == 1)
    cout << a[0];
  else if (n == 2)
    cout << (a[0] | a[1]);
  else {
    ll ans = 0;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        for (int k = j + 1; k < n; ++k)
          ans = max(ans, a[i] | a[j] | a[k]);
    cout << ans;
  }
}