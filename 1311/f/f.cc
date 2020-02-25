#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#define MAXN 200005

using namespace std;
typedef long long ll;

ll bit1[MAXN], bit2[MAXN];

int lowbit(int x) { return x & (-x); }

void update(ll *bit, int idx, ll delta) {
  for (; idx < MAXN; idx += lowbit(idx))
    bit[idx] += delta;
}

ll query(ll *bit, int idx) {
  ll ans = 0;
  for (; idx > 0; idx -= lowbit(idx))
    ans += bit[idx];
  return ans;
}

class Solution {
public:
  void solve() {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> x(n);
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &x[i].first);
      x[i].second = i;
    }
    for (int i = 0; i < n; ++i)
      scanf("%d", &v[i]);

    // Compress v
    set<int> sv(v.begin(), v.end());
    unordered_map<int, int> vdict;
    int idx = 0;
    for (int i : sv)
      vdict[i] = ++idx;

    // Sort x
    sort(x.begin(), x.end());

    memset(bit1, 0, sizeof(bit1));
    memset(bit2, 0, sizeof(bit2));
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
      int vj = vdict[v[x[i].second]];
      ll cnt = query(bit1, vj);
      ll sum = query(bit2, vj);
      ans += cnt * x[i].first - sum;
      update(bit1, vj, 1);
      update(bit2, vj, x[i].first);
    }

    printf("%lld", ans);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}