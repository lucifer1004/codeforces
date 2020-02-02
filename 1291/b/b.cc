#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  bool check(vector<int> &a) {
    int n = a.size();
    vector<bool> down(n);
    vector<int> tmp(a);
    tmp[n - 1] = 0;
    down[n - 1] = true;
    for (int i = n - 2; i >= 0; --i) {
      if (tmp[i] <= tmp[i + 1])
        break;
      tmp[i] = tmp[i + 1] + 1;
      down[i] = true;
    }
    if (down[0])
      return true;

    a[0] = 0;
    for (int i = 1; i < a.size(); ++i) {
      if (down[i] && a[i - 1] < a[i])
        return true;
      if (a[i] <= a[i - 1])
        return false;
      a[i] = a[i - 1] + 1;
    }
    return false;
  }

public:
  void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    if (check(a))
      printf("Yes\n");
    else
      printf("No\n");
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