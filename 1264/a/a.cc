#include <algorithm>
#include <iostream>
#include <vector>

#define MAX 1000005

using namespace std;

class Solution {
public:
  void solve() {
    int n;
    scanf("%d", &n);
    vector<int> cnt, sum;
    int p, curr = MAX;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &p);
      if (p < curr) {
        cnt.emplace_back(1);
        curr = p;
      } else {
        cnt[cnt.size() - 1]++;
      }
    }
    sum.emplace_back(0);
    for (int i = 0; i < cnt.size(); ++i)
      sum.emplace_back(sum[i] + cnt[i]);

    // Find no-medal split
    int no_medal_split =
        distance(sum.cbegin(), lower_bound(sum.cbegin(), sum.cend(), n / 2));
    if (sum[no_medal_split] > n / 2)
      no_medal_split--;
    if (no_medal_split < 2) {
      cout << "0 0 0" << endl;
      return;
    }
    int all = sum[no_medal_split];

    // Minimize silver split
    int silver_split = 0;
    int golden = cnt[0];

    // Iterate bronze split
    for (int bronze_split = 1; bronze_split < no_medal_split; ++bronze_split) {
      int golden_and_silver = sum[bronze_split + 1];
      int silver = golden_and_silver - golden;
      int bronze = all - golden_and_silver;
      if (silver > golden && bronze > golden) {
        cout << golden << " " << silver << " " << bronze << endl;
        return;
      }
    }
    cout << "0 0 0" << endl;
  }
};

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}