#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
public:
  void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    ll curr = 0;
    vector<int> ans;
    ans.reserve(k);
    for (int i = 0; i < n; ++i) {
      int a;
      scanf("%d", &a);
      curr += (ll)a;
      if (curr % 2 == 1 && ans.size() < k) {
        ans.emplace_back(i + 1);
        curr = 0;
      }
    }
    if (ans.size() == k && curr % 2 == 0) {
      ans[k - 1] = n;
      printf("YES\n");
      for (int i : ans)
        printf("%d ", i);
      printf("\n");
    } else
      printf("NO\n");
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