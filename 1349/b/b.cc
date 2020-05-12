#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    bool found = false;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] == k)
        found = true;
    }
    if (!found) {
      cout << "no" << endl;
      continue;
    }
    bool can = false;
    if (n == 1 && a[0] == k)
      can = true;
    auto solve = [&]() {
      int exceed = 0, len = 0;
      for (int i : a) {
        len++;
        if (i < k) {
          exceed--;
          if (exceed < 0) {
            exceed = 0;
            len = 0;
          }
        }
        if (i >= k && exceed >= 0 && len > 1) {
          can = true;
          break;
        }
        if (i >= k)
          exceed++;
      }
    };
    solve();
    if (!can) {
      reverse(a.begin(), a.end());
      solve();
    }
    cout << (can ? "yes" : "no") << endl;
  }
}