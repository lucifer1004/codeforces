#include <iostream>
#include <vector>

using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> cnt(n + 2);
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      cnt[a]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      ans += cnt[i] / i;
      cnt[i + 1] += cnt[i] % i;
    }
    cout << ans << endl;
  }
}
