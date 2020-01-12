#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const ll modulo = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> mat(n);
  for (int i = 0; i < n; ++i) cin >> mat[i];
  int na = 0, np = 0;
  vector<bool> col(m, true), row(n, true);
  bool uhas = false, bhas = false, lhas = false, rhas = false;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == 'A') {
        na++;
        if (i == 0) uhas = true;
        if (i == n - 1) bhas = true;
        if (j == 0) lhas = true;
        if (j == m - 1) rhas = true;
      } else {
        np++;
        col[j] = false;
        row[i] = false;
      }
    }

  bool ok = false;
  for (const bool &i : row) ok = ok || i;
  for (const bool &j : col) ok = ok || j;

  if (na == 0)
    cout << "MORTAL" << endl;
  else if (np == 0)
    cout << 0 << endl;
  else if (row[0] || row[n - 1] || col[0] || col[m - 1])
    cout << 1 << endl;
  else if (ok || mat[0][0] == 'A' || mat[0][m - 1] == 'A' ||
           mat[n - 1][0] == 'A' || mat[n - 1][m - 1] == 'A')
    cout << 2 << endl;
  else if (uhas || bhas || lhas || rhas)
    cout << 3 << endl;
  else
    cout << 4 << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}