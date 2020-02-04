#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define MAX 100005

using namespace std;
typedef long long ll;

mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }

ll a[100005];

int lowbit(int x) { return x & -x; }

void update(int idx, ll d) {
  for (; idx < MAX; idx += lowbit(idx))
    a[idx] += d;
}

ll query(int idx) {
  ll ans = 0;
  for (; idx > 0; idx -= lowbit(idx))
    ans += a[idx];
  return ans;
}

class Solution {
public:
  void solve() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < q; ++i) {
      ll t, p, q;
      scanf("%lld%lld%lld", &t, &p, &q);
      if (t == 1)
        update(p, q - (query(p) - query(p - 1)));
      else
        printf("%lld\n", query(q) - query(p - 1));
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  memset(a, 0, sizeof(a));
  int t;
  scanf("%d", &t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}