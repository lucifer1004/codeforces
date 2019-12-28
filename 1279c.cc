#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
typedef long long ll;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  unordered_map<int, int> pos;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  for (int i = 0; i < m; ++i) cin >> b[i];

  ll ans = 2 * pos[b[0]] + 1, top = pos[b[0]];
  for (int i = 1; i < m; ++i) {
    if (pos[b[i]] < top)
      ans++;
    else {
      ans += 2 * (pos[b[i]] - i) + 1;
      top = pos[b[i]];
    }
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}