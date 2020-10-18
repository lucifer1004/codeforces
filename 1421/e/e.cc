#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  vector<int> order(n);
  for (int i = 0; i < n; ++i)
    order[i] = i;
  sort(order.begin(), order.end(), [&](int i, int j) { return a[i] < a[j]; });
  ll ans = LLONG_MIN;
  int m = 0;
  if (n % 3 == 1)
    ans = sum;
  for (int i = 0; i < n; ++i) {
    sum -= 2 * a[order[i]];
    m++;
    if ((n + m) % 3 == 1) {
      if (abs(n - m - m) > 1)
        ans = max(ans, sum);
      else {
        vector<bool> check(n);
        for (int j = 0; j <= i; ++j)
          check[order[j]] = true;
        bool ok = false;
        for (int j = 0; j + 1 < n; ++j)
          if (check[j] == check[j + 1]) {
            ok = true;
            break;
          }
        if (!ok) {
          sum += 2 * a[order[i]];
          sum -= 2 * a[order[i + 1]];
          ans = max(ans, sum);
          sum -= 2 * a[order[i]];
          sum += 2 * a[order[i + 1]];
        } else
          ans = max(ans, sum);
      }
    }
  }
  cout << ans;
}