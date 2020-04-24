#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll check(vector<int> &a) {
  int n = a.size();
  ll ans = n;
  for (int i = 2; i <= n; ++i)
    for (int j = 0; j + i - 1 < n; ++j) {
      int lo = 100, hi = 0;
      for (int k = 0; k < i; ++k) {
        lo = min(lo, a[j + k]);
        hi = max(hi, a[j + k]);
      }
      if (hi - lo == i - 1) ans++;
    }
  return ans;
}

void solve() {
  for (int n = 1; n <= 10; ++n) {
    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = i + 1;

    ll ans = 0;
    do {
      ans += check(a);
    } while (next_permutation(a.begin(), a.end()));
    cout << "N = " << n << " Ans = " << ans << endl;
  }
}

int main() { solve(); }
