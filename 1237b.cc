#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    int d;
    scanf("%d", &d);
    a[d - 1] = i;
  }
  for (int i = 0; i < n; ++i) {
    int d;
    scanf("%d", &d);
    b[i] = a[d - 1];
  }
  int ans = 0;
  set<int> s;
  for (int i = 0; i < n; ++i) s.insert(i);
  for (int i = 0; i < n; ++i) {
    if (b[i] > *s.begin()) ans++;
    s.erase(b[i]);
  }
  cout << ans;
}