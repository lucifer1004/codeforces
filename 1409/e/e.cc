#include <cstdio>
#include <iostream>
#include <map>
#include <set>
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
    vector<int> x(n), y(n);
    set<int> s, start;
    for (int i = 0; i < n; ++i) {
      read(x[i]);
      s.insert(x[i]);
      start.insert(x[i]);
      s.insert(x[i] + k);
    }
    for (int i = 0; i < n; ++i)
      read(y[i]);
    int m = s.size();
    vector<int> pre(m + 1);
    vector<int> vs(s.begin(), s.end());
    map<int, int> d;
    for (int i = 0; i < m; ++i)
      d[vs[i]] = i + 1;
    for (int i : x)
      pre[d[i]]++;
    for (int i = 1; i <= m; ++i)
      pre[i] += pre[i - 1];
    vector<int> c(start.size() + 1);
    vector<int> L(m + 2), R(m + 2);
    for (int i : start) {
      int ds = d[i], de = d[i + k];
      L[ds] = R[ds] = pre[de] - pre[ds - 1];
    }
    for (int i = m - 1; i >= 0; --i)
      R[i] = max(R[i], R[i + 1]);
    int ans = 0;
    for (int i : start) {
      int ds = d[i], de = d[i + k];
      ans = max(ans, L[ds] + R[de + 1]);
    }
    printf("%d\n", ans);
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