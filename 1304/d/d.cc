#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  void shortest(int n, string &s) {
    vector<int> ans(n);
    int hi = n;
    int idx = 0;
    while (idx < n) {
      int left = idx;
      while (idx < n - 1 && s[idx] == '<')
        idx++;
      for (int i = idx; i >= left; --i)
        ans[i] = hi--;
      idx++;
    }
    for (int i : ans)
      cout << i << " ";
    cout << endl;
  }

  void longest(int n, string &s) {
    vector<int> ans(n);
    int lo = 1, hi = n;
    for (int i = 0; i < n - 1; ++i) {
      if (s[i] == '<')
        ans[i] = lo++;
      else
        ans[i] = hi--;
    }
    ans[n - 1] = lo;
    for (int i : ans)
      cout << i << " ";
    cout << endl;
  }

public:
  void solve() {
    int n;
    string s;
    cin >> n >> s;
    shortest(n, s);
    longest(n, s);
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