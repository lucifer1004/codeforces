#include <cstdio>
#include <iostream>

using namespace std;
typedef long long ll;

class Solution {
public:
  void solve() {
    ll n, ones;
    scanf("%lld%lld", &n, &ones);
    ll zeros = n - ones;
    if (ones == 0)
      printf("0\n");
    else if (ones == n)
      printf("%lld\n", n * (n + 1) / 2);
    else {
      ll sections = ones + 1;
      ll lo = zeros / sections;
      ll hi_num = zeros % sections;
      ll lo_num = sections - hi_num;
      ll zero_seg =
          lo_num * lo * (lo + 1) / 2 + hi_num * (lo + 1) * (lo + 2) / 2;
      ll ans = n * (n + 1) / 2 - zero_seg;
      printf("%lld\n", ans);
    }
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