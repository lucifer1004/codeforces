#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const ll modulo = 1e9 + 7;

void solve() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  ll current = s.size();
  for (ll i = 1; i <= n; ++i) {
    ll times = s[i - 1] - '1';
    current = (current + times * (current - i)) % modulo;
    current = (current + modulo) % modulo;
    if (s.size() < n) {
      string right(s.begin() + i, s.end());
      for (int j = 1; j <= times; ++j) s += right;
    }
  }
  cout << current << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}