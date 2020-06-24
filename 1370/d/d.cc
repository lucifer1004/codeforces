#include <iostream>
#include <vector>

using namespace std;
const int INF = 0x3f3f3f3f;

// Min-max when choosing k non-consecutive from a[l..r]
int solve(vector<int> &a, int l, int r, int k) {
  int lo = 1, hi = 1e9;
  vector<int> dp(a.size());
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    for (int i = l; i <= r; ++i) {
      dp[i] = a[i] <= mid;
      if (i >= l + 1)
        dp[i] = max(dp[i], dp[i - 1]);
      if (i >= l + 2 && a[i] <= mid)
        dp[i] = max(dp[i], dp[i - 2] + 1);
    }
    if (dp[r] >= k)
      hi = mid - 1;
    else
      lo = mid + 1;
  }
  return lo;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  int ans = INF;

  // min-max in even
  int rem = k / 2;
  int left = 1;
  int right = k % 2 == 0 ? n - 1 : n - 2;
  ans = min(ans, solve(a, left, right, rem));

  // min-max in odd
  rem = k / 2 + k % 2;
  left = 0;
  right = k % 2 == 0 ? n - 2 : n - 1;
  ans = min(ans, solve(a, left, right, rem));

  cout << ans;
}