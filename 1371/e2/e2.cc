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
  int lo = 1, hi = a.back() - 1;
  for (int i = 0; i < n; ++i) {
    lo = max(lo, a[i] - i);
    if (i - 1 + p < n)
      hi = min(hi, a[i - 1 + p] - 1 - i);
  }
  cout << max(0, hi - lo + 1) << endl;
  for (int i = lo; i <= hi; ++i)
    cout << i << " ";
}