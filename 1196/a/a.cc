#include <iostream>

using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << (a + b + c) / 2 << endl;
  }
}