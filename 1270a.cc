#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

void solve() {
  int n, k1, k2;
  cin >> n >> k1 >> k2;
  bool first_win = false;
  for (int i = 0; i < k1; ++i) {
    int a;
    cin >> a;
    if (a == n)
      first_win = true;
  }

  for (int i = 0; i < k2; ++i) {
    int b;
    cin >> b;
  }

  cout << (first_win ? "YES" : "NO") << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}