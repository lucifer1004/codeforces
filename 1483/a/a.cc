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
    int n, m;
    read(n), read(m);
    vector<vector<int>> days(m);
    vector<int> cnt(n + 1);
    vector<int> ans(m);
    for (int i = 0; i < m; i++) {
      int len;
      read(len);
      for (int j = 0; j < len; j++) {
        int idx;
        read(idx);
        days[i].emplace_back(idx);
      }
      if (len == 1) {
        cnt[days[i][0]]++;
        ans[i] = days[i][0];
      }
    }
    for (int i = 0; i < m; ++i) {
      if (ans[i]) continue;
      int lo = days[i][0];
      for (int j = 1; j < days[i].size(); ++j)
        if (cnt[days[i][j]] < cnt[lo]) lo = days[i][j];
      ans[i] = lo;
      cnt[lo]++;
    }
    for (int i = 1; i <= n; ++i)
      if (cnt[i] > (m + 1) / 2) {
        printf("NO\n");
        return;
      }
    printf("YES\n");
    for (int i = 0; i < m; ++i) printf("%d ", ans[i]);
    printf("\n");
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