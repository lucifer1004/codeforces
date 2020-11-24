#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
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
    int n;
    read(n);
    vector<vector<int>> s(n, vector<int>(log2(n) + 1));
    for (int i = 0; i < n; ++i)
      read(s[i][0]);
    for (int k = 1; k <= log2(n); ++k) {
      for (int i = 0; i < n; ++i) {
        s[i][k] = s[i][k - 1];
        int r = i + (1 << (k - 1));
        if (r < n)
          s[i][k] = min(s[i][k], s[r][k - 1]);
      }
    }
    auto query_min = [&](int l, int r) {
      int k = log2(r - l + 1);
      return min(s[l][k], s[r - (1 << k) + 1][k]);
    };
    vector<int> R(n);
    R[n - 1] = s[n - 1][0];
    for (int i = n - 2; i >= 0; --i)
      R[i] = max(R[i + 1], s[i][0]);
    int L = 0;
    for (int i = 0; i < n - 2; ++i) {
      L = max(L, s[i][0]);
      auto it1 = lower_bound(R.rbegin(), R.rend(), L);
      if (it1 == R.rend() || *it1 != L)
        continue;
      int hi = n - 1 - (int)(it1 - R.rbegin());
      auto it2 = upper_bound(R.rbegin(), R.rend(), L);
      int lo = max(i + 2, n - 1 - (int)(prev(it2) - R.rbegin()));
      while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int M = query_min(i + 1, mid - 1);
        if (M > L)
          lo = mid + 1;
        else if (M < L)
          hi = mid - 1;
        else {
          printf("YES\n");
          printf("%d %d %d\n", i + 1, mid - i - 1, n - mid);
          return;
        }
      }
    }
    printf("NO\n");
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