#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void solve() {
    int n;
    scanf("%d", &n);
    vector<int> p(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &p[i]);
    vector<int> ans = {p[0]};
    bool inc = p[1] > p[0];
    for (int i = 2; i < n; ++i) {
      if (inc && p[i] < p[i - 1]) {
        ans.emplace_back(p[i - 1]);
        inc = false;
      } else if (!inc && p[i] > p[i - 1]) {
        ans.emplace_back(p[i - 1]);
        inc = true;
      }
    }
    ans.emplace_back(p[n - 1]);
    printf("%d\n", (int)ans.size());
    for (int i : ans)
      printf("%d ", i);
    printf("\n");
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