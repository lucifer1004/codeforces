#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n), t(m);
  for (int i = 0; i < n; ++i) cin >> s[i];
  for (int j = 0; j < m; ++j) cin >> t[j];

  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int y;
    cin >> y;
    y--;
    cout << s[y % n] << t[y % m] << endl;
  }
}

int main() { solve(); }