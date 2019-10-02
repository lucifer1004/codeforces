#include <iostream>

using namespace std;

void solve() {
  int c, m, x;
  cin >> c >> m >> x;
  int ans = min(c, m);
  ans = min(ans, (c + m + x) / 3);
  cout << ans << endl;
}

int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i)
    solve();
  return 0;
}