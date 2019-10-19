#include <cmath>
#include <iostream>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int d;
    cin >> d;
    sum += d;
  }
  cout << sum / n + (sum % n > 0) << endl;
}

int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) solve();
}