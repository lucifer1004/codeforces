#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <set>

using namespace std;
typedef long long ll;

int left(int target, set<int> &s) {
  if (*s.begin() > target)
    return -1;
  return *prev(s.upper_bound(target));
}

int right(int target, set<int> &s) {
  auto it = s.lower_bound(target);
  if (it == s.end())
    return -1;
  return *it;
}

ll sqr(ll x) { return x * x; }

class Solution {
public:
  void solve() {
    int nr, ng, nb;
    scanf("%d%d%d", &nr, &ng, &nb);
    set<int> r, g, b;
    int ri, gi, bi;
    for (int i = 0; i < nr; ++i) {
      scanf("%d", &ri);
      r.insert(ri);
    }
    for (int i = 0; i < ng; ++i) {
      scanf("%d", &gi);
      g.insert(gi);
    }
    for (int i = 0; i < nb; ++i) {
      scanf("%d", &bi);
      b.insert(bi);
    }
    ll ans = LLONG_MAX;

    // R as mid
    for (ll ri : r) {
      ll lg = left(ri, g);
      ll rb = right(ri, b);
      if (lg != -1 && rb != -1)
        ans = min(ans, sqr(lg - ri) + sqr(lg - rb) + sqr(ri - rb));
      ll lb = left(ri, b);
      ll rg = right(ri, g);
      if (lb != -1 && rg != -1)
        ans = min(ans, sqr(lb - ri) + sqr(lb - rg) + sqr(ri - rg));
    }

    // G as mid
    for (int gi : g) {
      ll lr = left(gi, r);
      ll rb = right(gi, b);
      if (lr != -1 && rb != -1)
        ans = min(ans, sqr(lr - gi) + sqr(lr - rb) + sqr(gi - rb));
      ll lb = left(gi, b);
      ll rr = right(gi, r);
      if (lb != -1 && rr != -1)
        ans = min(ans, sqr(lb - gi) + sqr(lb - rr) + sqr(gi - rr));
    }

    // B as mid
    for (int bi : b) {
      ll lr = left(bi, r);
      ll rg = right(bi, g);
      if (lr != -1 && rg != -1)
        ans = min(ans, sqr(lr - bi) + sqr(lr - rg) + sqr(bi - rg));
      ll lg = left(bi, g);
      ll rr = right(bi, r);
      if (lg != -1 && rr != -1)
        ans = min(ans, sqr(lg - bi) + sqr(lg - rr) + sqr(bi - rr));
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