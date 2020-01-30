#include <climits>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  void solve() {
    string s, t;
    cin >> s >> t;
    set<char> ss, st;
    for (char si : s)
      ss.insert(si);
    for (char ti : t)
      st.insert(ti);
    for (char ti : st)
      if (ss.find(ti) == ss.end()) {
        cout << -1 << endl;
        return;
      }
    string ns;
    for (char si : s)
      if (st.find(si) != st.end())
        ns.push_back(si);
    s = ns;
    string ds = s + s;
    vector<vector<int>> nxt(ds.size(), vector<int>(26, INT_MAX));
    for (int i = ds.size() - 1; i > 0; --i) {
      for (int j = 0; j < 26; ++j) {
        if (ds[i] - 'a' == j)
          nxt[i - 1][j] = i;
        else
          nxt[i - 1][j] = nxt[i][j];
      }
    }
    int ans = 1, idx = 0;
    int i = 0;
    while (s[i] != t[idx])
      i++;
    while (idx < t.size() - 1) {
      i = nxt[i][t[++idx] - 'a'];
      if (i >= s.size()) {
        i %= s.size();
        ans++;
      }
    }
    cout << ans << endl;
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