#include <iostream>

using namespace std;

void solve() {
  int a, b, c, d, k;
  cin >> a >> b >> c >> d >> k;
  int pen = (a - 1) / c + 1;
  int pencil = (b - 1) / d + 1;
  if (pen + pencil <= k)
    cout << pen << " " << pencil << endl;
  else
    cout << -1 << endl;
}

int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) solve();
}
