#include <iostream>

using namespace std;

void solve() {
  int a, b, c, r;
  cin >> a >> b >> c >> r;
  int left = max(min(a, b), c - r);
  int right = min(max(a, b), c + r);
  int cover = max(right - left, 0);
  int uncover = abs(a - b) - cover;
  cout << uncover << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}