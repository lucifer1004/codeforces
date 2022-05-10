#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-') sig = -1;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

class Solution {
 public:
  void solve() {
    int n, q;
    read(n), read(q);
    vector<int> a(n), pre(n + 1);
    for (int i = 0; i < n; ++i) read(a[i]);
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; ++i) pre[i + 1] = pre[i] + a[i];

    while (q--) {
      int x;
      read(x);
      int ans = lower_bound(pre.begin(), pre.end(), x) - pre.begin();
      if (ans == n + 1)
        printf("-1\n");
      else
        printf("%d\n", ans);
    }
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