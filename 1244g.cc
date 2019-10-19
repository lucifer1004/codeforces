#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  ll n, k;
  cin >> n >> k;
  ll ans = n * (n + 1) / 2, rest = k - ans;
  if (rest < 0) {
    cout << -1;
    return 0;
  }
  vector<int> a(n);
  for (int i = 0; i < n; ++i) a[i] = i + 1;
  vector<int> b(a);
  ll l = 0, r = n - 1;
  while (l < r && rest > 0) {
    if (rest > r - l) {
      swap(b[l], b[r]);
      ans += r - l;
      rest -= r - l;
      l++;
      r--;
    } else {
      swap(b[l], b[l + rest]);
      ans += rest;
      break;
    }
  }
  cout << ans << endl;
  for (const int &i : a) cout << i << " ";
  cout << endl;
  for (const int &i : b) cout << i << " ";
  return 0;
}