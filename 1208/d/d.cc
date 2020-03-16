#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

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
    scanf("%d", &n);
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
      scanf("%lld", &a[i]);
    vector<int> ans(n);
    FenwickTree<ll> f(n);
    for (int i = 2; i <= n; ++i)
      f.update(i, i - 1);
    for (int i = n - 1; i >= 0; --i) {
      int l = 1, r = n;
      while (l <= r) {
        int mid = (l + r) / 2;
        ll fm = f.query(mid);
        if (fm <= a[i])
          l = mid + 1;
        else
          r = mid - 1;
      }
      ans[i] = l - 1;
      f.update(l, 1 - l);
    }
    for (int i : ans)
      printf("%d ", i);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}