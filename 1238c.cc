#include <climits>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void solve() {
  int h, n;
  cin >> h >> n;
  vector<int> p(n), f(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &p[i]);
  if (n == 1) {
    cout << 0 << endl;
    return;
  }
  f[0] = 0;
  f[1] = 1;
  for (int i = 2; i < n; ++i) {
    f[i] = f[i - 1] + 1;
    if (p[i - 1] == p[i] + 1)
      f[i] = min(f[i], f[i - 2]);
  }
  int ans = f[n - 1];
  if (p[n - 1] == 1)
    ans = min(ans, f[n - 2]);
  cout << ans << endl;
}

int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i)
    solve();
}