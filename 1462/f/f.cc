#include <algorithm>
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

template <class T> class FenwickTree {
  int limit;
  vector<T> arr;

  T lowbit(T x) { return x & (-x); }

public:
  FenwickTree(int limit) {
    this->limit = limit;
    arr = vector<T>(limit + 1);
  }

  void update(int idx, T delta) {
    for (; idx <= limit; idx += lowbit(idx))
      arr[idx] += delta;
  }

  T query(int idx) {
    T ans = 0;
    for (; idx > 0; idx -= lowbit(idx))
      ans += arr[idx];
    return ans;
  }
};

class Solution {
public:
  void solve() {
    int n;
    read(n);
    vector<pair<int, int>> segments;
    set<int> s;
    for (int i = 0; i < n; ++i) {
      int l, r;
      read(l), read(r);
      segments.emplace_back(l, r);
      s.insert(l);
      s.insert(r);
    }
    map<int, int> mp;
    int idx = 0;
    for (int si : s)
      mp[si] = ++idx;
    sort(segments.begin(), segments.end());
    FenwickTree<int> ft(idx);
    vector<int> intersect(n);
    for (int i = 0; i < n; ++i) {
      auto [l, r] = segments[i];
      int li = mp[l], ri = mp[r];
      intersect[i] += i - ft.query(li - 1);
      ft.update(ri, 1);
    }
    FenwickTree<int> ft2(idx);
    for (int i = n - 1; i >= 0; --i) {
      auto [l, r] = segments[i];
      int li = mp[l], ri = mp[r];
      intersect[i] += ft2.query(ri);
      ft2.update(li, 1);
    }
    int max_intersect = *max_element(intersect.begin(), intersect.end());
    printf("%d\n", n - 1 - max_intersect);
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