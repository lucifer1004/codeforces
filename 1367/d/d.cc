#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void solve() {
    string s;
    cin >> s;
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i)
      cin >> b[i];
    vector<int> cnt(26);
    for (char c : s)
      cnt[c - 'a']++;
    int now = 25;
    vector<char> ans(m);
    vector<int> q;
    for (int i = 0; i < m; ++i)
      if (b[i] == 0)
        q.emplace_back(i);
    while (!q.empty()) {
      vector<int> nq;
      while (cnt[now] < q.size())
        now--;
      for (int i : q) {
        ans[i] = 'a' + now;
        b[i] = -1;
      }
      for (int i = 0; i < m; ++i) {
        if (b[i] == -1)
          continue;
        for (int j : q)
          b[i] -= abs(i - j);
        if (b[i] == 0)
          nq.push_back(i);
      }
      now--;
      swap(q, nq);
    }
    string output(ans.begin(), ans.end());
    cout << output << endl;
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