#include <iostream>
#include <vector>

using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<bool> can(n, true);
  vector<pair<int, int>> p;
  for (int i = 0; i < m; ++i) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t == 0)
      p.emplace_back(l, r);
    else
      for (int j = l; j < r; ++j)
        can[j] = false;
  }
  for (auto [l, r] : p) {
    bool ok = false;
    for (int i = l; i < r; ++i)
      if (can[i]) {
        ok = true;
        break;
      }
    if (!ok) {
      cout << "NO";
      return 0;
    }
  }
  vector<int> ans(n, 1000);
  for (int i = 1; i < n; ++i) {
    if (can[i])
      ans[i] = ans[i - 1] - 1;
  }
  cout << "YES" << endl;
  for (int i : ans)
    cout << i << " ";
}