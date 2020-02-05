#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
  void solve() {
    int n;
    string s;
    cin >> n >> s;
    map<pair<int, int>, int> dict;
    dict[make_pair(0, 0)] = 0;
    int l = 0, r = 0, u = 0, d = 0;
    int ansl = -1, ansr = n + 1;
    for (int i = 0; i < n; ++i) {
      l += s[i] == 'L';
      r += s[i] == 'R';
      u += s[i] == 'U';
      d += s[i] == 'D';
      pair<int, int> p = make_pair(l - r, u - d);
      if (dict.find(p) != dict.end()) {
        int last = dict[p];
        if (i - last < ansr - ansl) {
          ansl = last + 1;
          ansr = i + 1;
        }
      }
      dict[p] = i + 1;
    }
    if (ansl == -1)
      cout << -1 << endl;
    else
      cout << ansl << " " << ansr << endl;
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