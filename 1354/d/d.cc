#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

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
    int n, q;
    scanf("%d%d", &n, &q);
    FenwickTree<int> ft = FenwickTree<int>(n);
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      ft.update(x, 1);
    }
    for (int i = 0; i < q; ++i) {
      int k;
      scanf("%d", &k);
      if (k > 0)
        ft.update(k, 1);
      else {
        k = -k;
        int l = 1, r = n;
        while (l <= r) {
          int mid = (l + r) / 2;
          int cnt = ft.query(mid);
          if (cnt < k)
            l = mid + 1;
          else
            r = mid - 1;
        }
        ft.update(l, -1);
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
      if (ft.query(i) > 0) {
        ans = i;
        break;
      }
    printf("%d", ans);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}