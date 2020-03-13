#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
public:
  void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i)
      scanf("%d", &b[i]);
    vector<int> d(n);
    for (int i = 0; i < n; ++i)
      d[i] = b[i] - a[i];
    sort(d.begin(), d.end());
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
      int left = a[i] - b[i];
      int cnt = lower_bound(d.begin(), d.end(), left) - d.begin();
      if (left > 0)
        cnt--;
      ans += cnt;
    }
    printf("%lld", ans / 2);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}