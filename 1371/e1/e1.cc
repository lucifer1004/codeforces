#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  int n, p;
  cin >> n >> p;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  sort(a.begin(), a.end());
  vector<int> ans;
  for (int i = 1; i < a.back(); ++i) {
    bool ok = true;
    int ways = 1;
    for (int j = 0; j < n; ++j) {
      int curr = i + j;
      int choices = upper_bound(a.begin(), a.end(), curr) - a.begin() - j;
      if (choices <= 0) {
        ok = false;
        break;
      }
      ways = ways * choices % p;
      if (ways == 0) {
        ok = false;
        break;
      }
    }
    if (ok)
      ans.emplace_back(i);
  }
  cout << ans.size() << endl;
  for (int i : ans)
    cout << i << " ";
}