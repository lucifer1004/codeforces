#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {

public:
  void solve() {
    int q, x;
    cin >> q >> x;
    int ans = 0;
    vector<int> cnt(x);
    vector<set<int>> dict(q + 1);
    for (int i = 0; i < x; ++i) {
      dict[0].insert(i);
    }
    for (int i = 0; i < q; ++i) {
      int xi;
      cin >> xi;
      int mod = xi % x;
      dict[cnt[mod]].erase(mod);
      dict[cnt[mod] + 1].insert(mod);
      cnt[mod]++;
      while (dict[ans].empty())
        ans++;
      cout << ans * x + *dict[ans].begin() << endl;
    }
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}