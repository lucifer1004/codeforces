#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int hi = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      hi = max(hi, a[i]);
    }
    int ans = -1, cnt = 0;
    for (int i = 0; i < n; ++i)
      if (a[i] == hi) {
        cnt++;
        if ((i > 0 && a[i - 1] < hi) || (i + 1 < n && a[i + 1] < hi))
          ans = i + 1;
      }
    if (cnt == n)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
}