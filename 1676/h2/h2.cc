#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;
using ll = long long;

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

template <class T>
class FenwickTree {
  int limit;
  vector<T> arr;

  int lowbit(int x) { return x & (-x); }

 public:
  FenwickTree(int limit) {
    this->limit = limit;
    arr = vector<T>(limit + 1);
  }

  void update(int idx, T delta) {
    for (; idx <= limit; idx += lowbit(idx)) arr[idx] += delta;
  }

  T query(int idx) {
    T ans = 0;
    for (; idx > 0; idx -= lowbit(idx)) ans += arr[idx];
    return ans;
  }
};

class Solution {
 public:
  void solve() {
    int n;
    read(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) read(a[i]);
    set<int> s(a.begin(), a.end());
    unordered_map<int, int> mp;
    int id = 0;
    for (int si : s) mp[si] = ++id;

    int m = s.size();
    FenwickTree<int> ft(m);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      int id = mp[a[i]];
      ans += i - ft.query(id - 1);
      ft.update(id, 1);
    }

    printf("%lld\n", ans);
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