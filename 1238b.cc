#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n, r;
  cin >> n >> r;
  vector<int> x(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &x[i]);
  sort(x.begin(), x.end());
  int shots = 1, curr = x[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    if (x[i] == curr)
      continue;
    if (x[i] <= shots * r)
      break;
    else {
      curr = x[i];
      shots++;
    }
  }
  cout << shots << endl;
}

int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i)
    solve();
}