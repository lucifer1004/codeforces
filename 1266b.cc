#include <iostream>

using namespace std;

typedef long long ll;

void solve() {
  ll n;
  cin >> n;
  ll rest = n % 14;
  if (n > 14 && rest >= 1 && rest <= 6)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}