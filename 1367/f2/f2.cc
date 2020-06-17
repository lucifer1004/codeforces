#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    map<int, vector<int>> distinct;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
      distinct[a[i]].emplace_back(i);
    }
    vector<vector<int>> d;
    int hi = 0;
    for (auto p : distinct) {
      hi = max(hi, (int)p.second.size());
      d.emplace_back(p.second);
    }
    int m = d.size();

    // Case 1: H-T
    for (int i = 0; i < m - 1; ++i) {
      for (int j = 0; j < d[i].size(); ++j) {
        int r = d[i + 1].end() -
                upper_bound(d[i + 1].begin(), d[i + 1].end(), d[i][j]);
        hi = max(hi, j + 1 + r);
      }
    }

    // Case 2: H-X-...-X-T
    int l = n, r = -1, mid = 0, start = 0;
    for (int i = 0; i < m; ++i) {
      if (d[i].front() < r) {
        int right = d[i].end() - upper_bound(d[i].begin(), d[i].end(), r);
        int left = 0;
        if (start > 0)
          left += d[start - 1].size() -
                  (d[start - 1].end() -
                   upper_bound(d[start - 1].begin(), d[start - 1].end(), l));
        hi = max(hi, mid + left + right);
        start = i;
        mid = d[i].size();
        l = d[i].front();
        r = d[i].back();
      } else {
        mid += d[i].size();
        r = d[i].back();
        if (i == m - 1) {
          if (start > 0)
            mid += d[start - 1].size() -
                   (d[start - 1].end() -
                    upper_bound(d[start - 1].begin(), d[start - 1].end(), l));
          hi = max(hi, mid);
        }
      }
    }
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