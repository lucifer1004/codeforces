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
    int n, d12, d23, d31;
    read(n), read(d12), read(d23), read(d31);

    int hi = max(d12, max(d23, d31));
    if (d12 + d23 + d31 - hi < hi || (d12 + d23 + d31) % 2 == 1) {
      printf("NO\n");
      return;
    }

    vector<vector<int>> adj(n + 1);
    int p = 4;
    bool valid = true;

    auto safe_add = [&](int start, int end) {
      if (start > n || end > n || start == end) {
        valid = false;
      } else {
        adj[start].push_back(end);
      }
    };

    auto connect = [&](int start, int end, int length) {
      if (length == 1) {
        safe_add(start, end);
      } else {
        safe_add(start, p);
        for (int i = 1; i < length - 1; ++i) {
          safe_add(p, p + 1);
          p++;
        }
        safe_add(p, end);
        p++;
      }
    };

    if (d12 + d23 == d31) {
      // 2 on path 1--3
      connect(1, 2, d12);
      connect(2, 3, d23);
    } else if (d12 + d31 == d23) {
      // 1 on path 2--3
      connect(2, 1, d12);
      connect(1, 3, d31);
    } else if (d23 + d31 == d12) {
      // 3 on path 1--2
      connect(1, 3, d31);
      connect(3, 2, d23);
    } else {
      p = 5;
      int a = (d12 + d23 + d31) / 2 - d23;
      int b = (d12 + d23 + d31) / 2 - d31;
      int c = (d12 + d23 + d31) / 2 - d12;
      connect(4, 1, a);
      connect(4, 2, b);
      connect(4, 3, c);
    }

    if (!valid) {
      printf("NO\n");
      return;
    }

    while (p <= n)
      adj[1].push_back(p++);

    printf("YES\n");
    for (int i = 1; i <= n; ++i) {
      for (int j : adj[i])
        printf("%d %d\n", i, j);
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