#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n * 3);
  int lo = INT_MAX, hi = INT_MIN;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    a[i + 2 * n] = a[i + n] = a[i];
    lo = min(lo, a[i]);
    hi = max(hi, a[i]);
  }

  // Case 1: No solution
  if (lo * 2 >= hi) {
    for (int i = 0; i < n; ++i)
      cout << -1 << " ";
    return 0;
  }

  // Case 2: Ordinary
  vector<int> ans(n * 3);
  priority_queue<pair<int, int>> q;
  for (int i = 0; i < n * 3; ++i) {
    while (!q.empty() && q.top().first > 2 * a[i]) {
      int idx = q.top().second;
      ans[idx] = i - idx;
      q.pop();
    }
    q.push({a[i], i});
  }

  int curr = 1e6;
  for (int i = 3 * n - 1; i >= 0; --i) {
    if (!ans[i] || ans[i] > curr)
      ans[i] = curr;
    curr = min(curr, ans[i]) + 1;
  }

  for (int i = 0; i < n; ++i)
    cout << ans[i] << " ";
}