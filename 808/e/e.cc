#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

typedef long long ll;
typedef std::priority_queue<ll, std::vector<ll>, std::greater<ll>> minheap;
typedef std::priority_queue<ll> maxheap;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<ll> w(n), c(n);
  for (int i = 0; i < n; ++i)
    scanf("%lld%lld", &w[i], &c[i]);
  std::vector<int> order(n);
  for (int i = 0; i < n; ++i)
    order[i] = i;
  std::sort(order.begin(), order.end(), [&](int i, int j) {
    ll ui = c[i] * w[j], uj = c[j] * w[i];
    return ui > uj || (ui == uj && w[i] > w[j]);
  });
  ll ans = 0;
  std::vector<minheap> min(4);
  std::vector<maxheap> max(4);
  for (int i = 0; i < n; ++i)
    max[w[i]].push(c[i]);
  for (int i = 0; i < n && m > 0; ++i) {
    int j = order[i];
    if (m >= w[j]) {
      m -= w[j];
      ans += c[j];
      min[w[j]].push(c[j]);
      max[w[j]].pop();
    } else {
      if (m == 1) {
        ll la1 = 1e16, la2 = 1e16, lb1 = 1e16, lc1 = 1e16;
        ll ra1 = 0, rb1 = 0, rb2 = 0, rc1 = 0;
        if (!min[1].empty()) {
          la1 = min[1].top();
          min[1].pop();
          if (!min[1].empty())
            la2 = min[1].top();
        }
        if (!min[2].empty())
          lb1 = min[2].top();
        if (!min[3].empty())
          lc1 = min[3].top();
        if (!max[1].empty())
          ra1 = max[1].top();
        if (!max[2].empty()) {
          rb1 = max[2].top();
          max[2].pop();
          if (!max[2].empty())
            rb2 = max[2].top();
        }
        if (!max[3].empty())
          rc1 = max[3].top();
        std::vector<ll> candidates = {ans + ra1, ans - la1 + rb1,
                                      ans - lb1 + rc1, ans - la1 - la2 + rc1,
                                      ans - lc1 + rb1 + rb2};
        ans = *std::max_element(candidates.begin(), candidates.end());
        break;
      } else {
        ll la1 = 1e16, lb1 = 1e16;
        ll ra1 = 0, ra2 = 0, rb1 = 0, rc1 = 0;
        if (!min[1].empty())
          la1 = min[1].top();
        if (!min[2].empty())
          lb1 = min[2].top();
        if (!max[1].empty()) {
          ra1 = max[1].top();
          max[1].pop();
          if (!max[1].empty())
            ra2 = max[1].top();
        }
        if (!max[2].empty())
          rb1 = max[2].top();
        if (!max[3].empty())
          rc1 = max[3].top();
        std::vector<ll> candidates = {ans + ra1 + ra2, ans + rb1,
                                      ans - lb1 + ra1 + rc1, ans - la1 + rc1};
        ans = *std::max_element(candidates.begin(), candidates.end());
        break;
      }
    }
  }
  printf("%lld", ans);
}