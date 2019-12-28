#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
typedef unsigned long long ll;
const ll modulo = 998244353;
const ll rev = 998244351;

ll fast_mul(ll x, ll y) {
  if (x == 1) return 1;
  if (y == 0) return 1;
  if (y == 1) return x;
  ll half = fast_mul(x, y / 2);
  ll ans = half * half % modulo;
  if (y % 2 == 1) ans = ans * x % modulo;
  return ans;
}

void solve() {
  int n;
  cin >> n;
  unordered_map<int, int> wanted;
  vector<vector<int>> want(n);
  for (int i = 0; i < n; ++i) {
    int ki;
    cin >> ki;
    for (int j = 0; j < ki; ++j) {
      int wi;
      cin >> wi;
      want[i].push_back(wi);
      wanted[wi]++;
    }
  }

  ll ans = 0;
  ll nmod = fast_mul(n, rev);
  nmod = nmod * nmod % modulo;
  for (int i = 0; i < n; ++i) {
    int k = want[i].size();
    for (const int &j : want[i]) {
      ll kmod = fast_mul(k, rev);
      ll pos = nmod * kmod % modulo;
      pos = pos * wanted[j] % modulo;
      ans = (ans + pos) % modulo;
    }
  }

  cout << ans;
}

int main() { solve(); }