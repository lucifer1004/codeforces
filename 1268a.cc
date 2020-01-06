#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  string a;
  cin >> a;
  bool special = false;
  int small = 1e7, big = 1e7;
  for (int i = 0; i < k; ++i) {
    for (int j = i + k; j < n; j += k) {
      if (a[j] < a[i]) {
        small = min(small, j);
        break;
      }
      if (a[j] > a[i]) {
        big = min(big, j);
        break;
      }
    }
  }

  if (big < small) {
    int c = k - 1;
    while (c >= 0) {
      if (a[c] <= '8') {
        a[c]++;
        break;
      }
      c--;
    }
    for (int i = c + 1; i < k; ++i) a[i] = '0';
  }
  for (int i = 0; i < k; ++i)
    for (int j = i; j < n; j += k) a[j] = a[i];

  cout << n << endl;
  cout << a;
}

int main() { solve(); }