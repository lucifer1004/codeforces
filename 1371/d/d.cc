#include <iostream>
#include <vector>

using namespace std;
int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    int i = 0, j = 0, k0 = k;
    while (k--) {
      a[i][j] = 1;
      i++, j++;
      if (i == n) {
        i = 0;
        j++;
      }
      j %= n;
    }
    cout << (k0 % n == 0 ? 0 : 2) << endl;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
        cout << a[i][j];
      cout << endl;
    }
  }
}