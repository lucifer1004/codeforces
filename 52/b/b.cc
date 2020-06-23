#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> mat(n);
  vector<int> row(n), col(m);
  for (int i = 0; i < n; ++i) {
    cin >> mat[i];
    for (int j = 0; j < m; ++j)
      if (mat[i][j] == '*') {
        row[i]++;
        col[j]++;
      }
  }
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] != '*')
        continue;
      ans += (ll)(row[i] - 1) * (col[j] - 1);
    }
  }
  cout << ans;
}