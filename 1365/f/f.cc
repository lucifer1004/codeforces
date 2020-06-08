#include <iostream>
#include <map>
#include <vector>

using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    for (int i = 0; i < n; ++i)
      cin >> b[i];
    if (n % 2 == 1 && a[n / 2] != b[n / 2]) {
      cout << "No" << endl;
      continue;
    }
    map<pair<int, int>, int> m;
    for (int i = 0; i < n / 2; ++i) {
      m[{a[i], a[n - 1 - i]}]++;
      m[{a[n - 1 - i], a[i]}]++;
    }
    for (int i = 0; i < n / 2; ++i) {
      m[{b[i], b[n - 1 - i]}]--;
      m[{b[n - 1 - i], b[i]}]--;
    }
    bool ok = true;
    for (auto p : m)
      if (p.second < 0)
        ok = false;
    cout << (ok ? "Yes" : "No") << endl;
  }
}