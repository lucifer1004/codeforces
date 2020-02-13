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
    sort(a.begin(), a.end());
    int ans = n, right = n / 2;
    for (int i = 0; i < n / 2; ++i) {
      while (right < n && a[right] < a[i] * 2)
        right++;
      if (right < n) {
        ans--;
        right++;
      }
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