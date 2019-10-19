#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  char curr = s[0];
  int num = 1;
  vector<ll> cnt;
  for (int i = 1; i < n; ++i) {
    if (s[i] == curr)
      num++;
    else {
      curr = s[i];
      cnt.emplace_back(num);
      num = 1;
    }
  }
  cnt.emplace_back(num);

  ll anti = 0;
  int m = cnt.size();
  for (int i = 0; i < m - 1; ++i)
    anti += cnt[i] + cnt[i + 1] - 1;

  ll ans = n * (n - 1) / 2 - anti;
  cout << ans;
  return 0;
}