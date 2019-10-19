#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int lo = INT_MAX, hi = INT_MIN;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    lo = min(lo, a[i]);
    hi = max(hi, a[i]);
  }

  // Case 1: No solution
  if (lo * 2 >= hi) {
    for (int i = 0; i < n; ++i) cout << -1 << " ";
    return 0;
  }

  // Case 2: Ordinary
  vector<int> ans(n);
  priority_queue<pair<int, int>> q;
  for (int i = 0; i < n * 2; ++i) {
    while (!q.empty() && q.top().first > 2 * a[i % n]) {
      int idx = q.top().second;
      ans[idx] = i - idx;
      q.pop();
    }
    if (i < n) q.push({a[i], i});
  }

  int curr = 1e6;
  for (int i = 2 * n - 1; i >= 0; --i) {
    int id = i % n;
    if (!ans[id] || ans[id] > curr) ans[id] = curr;
    curr = min(curr, ans[id]) + 1;
  }

  for (int i = 0; i < n; ++i) cout << ans[i] << " ";
}