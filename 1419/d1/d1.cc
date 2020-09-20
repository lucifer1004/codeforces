#include <algorithm>
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
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      read(a[i]);
    sort(a.begin(), a.end());
    vector<int> ans(n);
    for (int i = 0; i < n / 2; ++i)
      ans[i * 2 + 1] = a[i];
    for (int i = 0; i <= n / 2; ++i) {
      if (i * 2 < n)
        ans[i * 2] = a[i + n / 2];
    }
    int cnt = 0;
    for (int i = 1; i < n - 1; ++i)
      if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1])
        cnt++;
    printf("%d\n", cnt);
    for (int i : ans)
      printf("%d ", i);
    printf("\n");
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}