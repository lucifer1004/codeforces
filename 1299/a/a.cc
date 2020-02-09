#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n + 1);
    vector<int> cnt(32), first(32);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      for (int j = 0; j < 32; ++j)
        if (a[i] & (1 << j)) {
          cnt[j]++;
          if (cnt[j] == 1)
            first[j] = i;
          else
            first[j] = 0;
        }
    }
    set<int> used;
    for (int i = 31; i >= 0; --i) {
      if (first[i] != 0 && used.find(first[i]) == used.end()) {
        printf("%d ", a[first[i]]);
        used.insert(first[i]);
      }
    }
    for (int i = 1; i <= n; ++i)
      if (used.find(i) == used.end())
        printf("%d ", a[i]);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}