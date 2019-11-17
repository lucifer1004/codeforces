#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  for (int i = 0; i < n; ++i) {
    int bi;
    cin >> bi;
    a[i] = bi - a[i];
  }
  int i = 0;
  while (i < n && a[i] == 0)
    i++;
  if (i != n) {
    int d = a[i];
    if (d < 0) {
      cout << "NO" << endl;
      return;
    }
    int j = i + 1;
    while (j < n && a[j] == d)
      j++;
    while (j < n && a[j] == 0)
      j++;
    if (j != n) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}

int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i)
    solve();
}