#include <iostream>
#include <vector>

using namespace std;
using ll = int64_t;
const ll MOD = 1e9 + 7;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  ll a = 0, ab = 0, abc = 0, t = 1;
  int q = 0;
  for (char c : s) {
    switch (c) {
      case 'a':
        a = (a + t) % MOD;
        break;
      case 'b':
        ab = (ab + a) % MOD;
        break;
      case 'c':
        abc = (abc + ab) % MOD;
        break;
      default:
        ll na = a, nab = ab, nabc = abc;
        na = (a * 3 + t) % MOD;
        nab = (ab * 3 + a) % MOD;
        nabc = (abc * 3 + ab) % MOD;
        t = t * 3 % MOD;
        a = na, ab = nab, abc = nabc;
    }
  }
  cout << abc;
}