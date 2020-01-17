#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
 public:
  void solve() {
    int n;
    cin >> n;
    vector<string> str(n);
    unordered_set<string> dict;
    vector<int> oz, zo;
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      dict.insert(s);
      str[i] = s;
    }
    int noo = 0, noz = 0, nzo = 0, nzz = 0;
    for (int i = 0; i < n; ++i) {
      string s = str[i];
      int l = s.size();
      if (s[0] == '0' && s[l - 1] == '0') {
        nzz++;
      }
      if (s[0] == '1' && s[l - 1] == '1') {
        noo++;
      }
      if (s[0] == '0' && s[l - 1] == '1') {
        nzo++;
        string t = s;
        reverse(t.begin(), t.end());
        bool can_reverse = dict.find(t) == dict.end();
        if (can_reverse) zo.push_back(i);
      }
      if (s[0] == '1' && s[l - 1] == '0') {
        noz++;
        string t = s;
        reverse(t.begin(), t.end());
        bool can_reverse = dict.find(t) == dict.end();
        if (can_reverse) oz.push_back(i);
      }
    }
    int coz = oz.size(), czo = zo.size();
    if (noo > 0 && nzz > 0 && (noz + nzo == 0)) {
      // 00 and 11, while no 01 or 10
      cout << -1 << endl;
    } else {
      int delta = abs(noz - nzo) / 2;
      if (delta == 0) {
        // |01 - 10| <= 1, no need to reverse
        cout << 0 << endl;
      } else {
        if (noz > nzo) {
          // 10 > 01
          if (coz < delta) {
            // Cannot reverse that many.
            cout << -1 << endl;
          } else {
            // Reverse delta 10 to 01.
            cout << delta << endl;
            for (int i = 0; i < delta; ++i) cout << oz[i] + 1 << " ";
            cout << endl;
          }
        } else {
          // 01 > 10
          if (czo < delta) {
            // Cannot reverse that many.
            cout << -1 << endl;
          } else {
            // Reverse delta 01 to 10.
            cout << delta << endl;
            for (int i = 0; i < delta; ++i) cout << zo[i] + 1 << " ";
            cout << endl;
          }
        }
      }
    }
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