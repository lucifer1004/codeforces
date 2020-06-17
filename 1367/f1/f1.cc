#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    vector<int> order(n);
    for (int i = 0; i < n; ++i)
      order[i] = i;
    sort(order.begin(), order.end(), [&](int i, int j) { return a[i] < a[j]; });
    vector<int> dp(n);
    int hi = 1, curr = 1;
    for (int i = 1; i < n; ++i) {
      if (order[i] > order[i - 1])
        curr++;
      else {
        hi = max(hi, curr);
        curr = 1;
      }
    }
    hi = max(hi, curr);
    cout << n - hi << endl;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  scanf("%d", &t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}