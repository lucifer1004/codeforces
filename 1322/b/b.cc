#include <algorithm>
#include <bitset>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// query number of values ∈ [l,r) in sorted array a.
int query(vector<int> &a, int k, int l, int r) {
  l -= a[k], r -= a[k];
  auto left = lower_bound(a.begin() + k + 1, a.end(), l);
  auto right = lower_bound(a.begin() + k + 1, a.end(), r);
  return right - left;
}

class Solution {
public:
  void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    bitset<32> ans(0);
    for (int i = 0; i < 25; ++i) {
      vector<int> ak(a);
      for (int &aki : ak)
        aki %= (1 << (i + 1));
      sort(ak.begin(), ak.end());
      ll cnt = 0;
      for (int k = 0; k < n - 1; ++k) {
        // [2^i, 2^(i+1)-1]
        cnt += query(ak, k, 1 << i, 1 << (i + 1));
        // [3*2^i, 2^(i+2)-1]
        cnt += query(ak, k, 3 * (1 << i), 1 << (i + 2));
      }
      if (cnt & 1)
        ans.set(i);
    }
    printf("%lld", ans.to_ullong());
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}