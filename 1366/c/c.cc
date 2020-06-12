#include <iostream>
#include <vector>

using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> one(n + m - 1), zero(n + m - 1);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        int num;
        cin >> num;
        int pos = i + j;
        one[pos] += num;
        zero[pos] += num == 0;
      }
    int ans = 0;
    for (int i = 0; i < (n + m - 1) / 2; ++i) {
      int o = one[i] + one[n + m - 2 - i];
      int z = zero[i] + zero[n + m - 2 - i];
      ans += min(o, z);
    }
    cout << ans << endl;
  }
}