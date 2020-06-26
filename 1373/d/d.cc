#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

template <typename T> void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-')
      sig = -1;
  for (; isdigit(c); c = getchar())
    x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

class Solution {
  ll calc(vector<int> &b) {
    int n = b.size();
    vector<ll> dp(n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
      dp[i] = max(0ll, dp[i - 1]) + b[i - 1];
      ans = max(ans, dp[i]);
    }
    return ans;
  }

public:
  void solve() {
    int n;
    read(n);
    vector<int> a(n);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
      read(a[i]);
      if (i % 2 == 0)
        ans += a[i];
    }
    ll extra = 0;
    vector<int> b;
    for (int i = 0; 2 * i + 1 < n; ++i)
      b.emplace_back(a[2 * i + 1] - a[2 * i]);
    extra = max(extra, calc(b));
    b.clear();
    for (int i = 0; 2 * i + 2 < n; ++i)
      b.emplace_back(a[2 * i + 1] - a[2 * i + 2]);
    extra = max(extra, calc(b));
    ans += extra;
    cout << ans << endl;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  read(t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}