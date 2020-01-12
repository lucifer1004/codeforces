#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  for (int i = 0; i < n - 1; ++i) {
    if (abs(a[i] - a[i + 1]) >= 2) {
      cout << "YES" << endl;
      cout << i + 1 << " " << i + 2 << endl;
      return;
    }
  }

  cout << "NO" << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}