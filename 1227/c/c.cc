#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  void output(vector<pair<int, int>> &ops) {
    cout << ops.size() << endl;
    for (auto op : ops)
      cout << op.first << " " << op.second << endl;
  }

public:
  void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string t;
    for (int i = 0; i < k - 1; ++i)
      t += "()";
    int l = (n - 2 * k + 2) / 2;
    for (int i = 0; i < l; ++i)
      t += "(";
    for (int i = 0; i < l; ++i)
      t += ")";
    vector<pair<int, int>> ops;
    for (int i = 0; i < n; ++i) {
      if (s[i] != t[i]) {
        int next = i + 1;
        while (s[next] != t[i])
          next++;
        reverse(s.begin() + i, s.begin() + next + 1);
        ops.emplace_back(i + 1, next + 1);
      }
    }
    output(ops);
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}