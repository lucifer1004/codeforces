#include <algorithm>
#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> sugars(n);
  vector<vector<ll>> count(m, vector<ll>{0});
  for (int i = 0; i < n; ++i)
    cin >> sugars[i];
  sort(sugars.begin(), sugars.end());
  for (int i = 0; i < n; ++i) {
    int mod = i % m;
    int div = i / m;
    count[mod].emplace_back(count[mod][div] + sugars[i]);
  }

  vector<ll> ans(n);
  ans[0] = sugars[0];
  for (int i = 1; i < n; ++i) {
    int mod = i % m;
    int div = i / m;
    ans[i] = ans[i - 1] + count[mod][div + 1];
  }
  for (int i = 0; i < n; ++i)
    cout << ans[i] << " ";
  return 0;
}