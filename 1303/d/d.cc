#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
public:
  void solve() {
    ll n, m;
    scanf("%lld%lld", &n, &m);
    vector<ll> a(m);
    ll sum = 0;
    unordered_map<ll, int> cnt;
    for (int i = 0; i < m; ++i) {
      scanf("%lld", &a[i]);
      sum += a[i];
      cnt[a[i]]++;
    }
    if (sum < n) {
      printf("-1\n");
      return;
    }
    ll ans = 0;
    for (int i = 0; i < 62; ++i) {
      ll curr = (1ll << i);
      if (n & curr) {
        if (cnt[curr] == 0) {
          int j = i + 1;
          while (cnt[1ll << j] == 0)
            j++;
          cnt[1ll << j]--;
          for (int k = j - 1; k > i; --k)
            cnt[1ll << k]++;
          cnt[1ll << i] += 2;
          ans += j - i;
        }
        cnt[curr]--;
      }
      cnt[curr << 1] += cnt[curr] / 2;
      cnt[curr] %= 2;
    }
    printf("%lld\n", ans);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  scanf("%d", &t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}