#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<bool> ladder(n);
  int cnt = 0, l = n, r = -1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      cnt++;
      l = min(l, i);
      r = max(r, i);
    }
  }
  if (!cnt)
    cout << n << endl;
  else {
    int ans = n + cnt;
    ans = max(ans, 2 * r + 2);
    ans = max(ans, 2 * n - 2 * l);
    cout << ans << endl;
  }
}

int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i)
    solve();
}