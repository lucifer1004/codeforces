#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

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
public:
  void solve() {
    int n, k;
    read(n), read(k);
    vector<int> a, b, ab;
    int asum = 0, bsum = 0;
    for (int i = 0; i < n; ++i) {
      int ti, ai, bi;
      read(ti), read(ai), read(bi);
      asum += ai;
      bsum += bi;
      if (!ai && !bi)
        continue;
      if (ai && bi)
        ab.emplace_back(ti);
      else if (ai)
        a.emplace_back(ti);
      else
        b.emplace_back(ti);
    }
    if (asum < k || bsum < k) {
      printf("-1");
      return;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(ab.begin(), ab.end());
    vector<int> pa(a.size()), pb(b.size()), pab(ab.size());
    partial_sum(a.begin(), a.end(), pa.begin());
    partial_sum(b.begin(), b.end(), pb.begin());
    partial_sum(ab.begin(), ab.end(), pab.begin());
    int ans = INT_MAX;
    for (int i = max(0, k - (int)ab.size());
         i <= min(k, (int)min(a.size(), b.size())); ++i) {
      int curr = 0;
      if (i > 0) {
        curr += pa[i - 1];
        curr += pb[i - 1];
      }
      if (k - i > 0)
        curr += pab[k - i - 1];
      ans = min(ans, curr);
    }
    printf("%d", ans);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}