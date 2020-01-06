#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

void solve() {
  ll r, g, b;
  cin >> r >> g >> b;
  ll m = max(r, max(g, b));
  ll rest = r + g + b - m;
  if (m <= rest + 1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}