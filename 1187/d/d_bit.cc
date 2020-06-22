#include <cstdio>
#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f

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

template <class T> class FenwickTree {
  int limit;
  vector<T> arr;

  T lowbit(T x) { return x & (-x); }

public:
  FenwickTree(int limit) {
    this->limit = limit;
    arr = vector<T>(limit + 1);
  }

  void update(int idx, T x) {
    for (; idx <= limit; idx += lowbit(idx))
      arr[idx] = max(arr[idx], x);
  }

  T query(int idx) {
    T ans = 0;
    for (; idx > 0; idx -= lowbit(idx))
      ans = max(ans, arr[idx]);
    return ans;
  }
};

class Solution {
public:
  void solve() {
    int n;
    read(n);
    vector<int> a(n), b(n), p(n);
    vector<vector<int>> s(n + 1);
    for (int i = 0; i < n; ++i)
      read(a[i]);
    for (int i = 0; i < n; ++i)
      read(b[i]), s[b[i]].emplace_back(i);
    for (int i = n - 1; i >= 0; --i) {
      if (s[a[i]].empty()) {
        printf("NO\n");
        return;
      }
      p[i] = s[a[i]].back(), s[a[i]].pop_back();
    }
    FenwickTree<int> ft(n);
    for (int i = 0; i < n; ++i) {
      if (ft.query(a[i] - 1) > p[i]) {
        printf("NO\n");
        return;
      }
      ft.update(a[i], p[i]);
    }
    printf("YES\n");
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