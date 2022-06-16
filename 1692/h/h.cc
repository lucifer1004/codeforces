#include <cstdio>
#include <iostream>
#include <map>
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
    int n;
    read(n);

    int l = 1, r = 1, ans = 1, choice = 0;
    map<int, vector<int>> p;
    for (int i = 0; i < n; ++i) {
      int x;
      read(x);
      if (!choice) choice = x;
      p[x].push_back(i);
    }

    for (auto [num, v] : p) {
      int mini = 0, minv = 1000000;
      for (int i = 0; i < v.size(); ++i) {
        int now = 2 * i - v[i];
        if (i > 0) {
          int cur = now - minv + 1;
          if (cur > ans) {
            ans = cur;
            choice = num;
            l = v[mini] + 1;
            r = v[i] + 1;
          }
        }
        if (now < minv) {
          minv = now;
          mini = i;
        }
      }
    }

    printf("%d %d %d\n", choice, l, r);
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