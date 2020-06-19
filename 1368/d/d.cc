#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> cnt(20);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    for (int j = 0; j < 20; ++j)
      if (a[i] & (1 << j))
        cnt[j]++;
  }
  ll ans = 0;
  bool found = true;
  while (found) {
    ll curr = 0;
    found = false;
    for (int i = 19; i >= 0; --i) {
      if (cnt[i] > 0) {
        cnt[i]--;
        found = true;
        curr += (1 << i);
      }
    }
    ans += curr * curr;
  }
  cout << ans;
}