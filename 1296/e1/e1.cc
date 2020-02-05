#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> ans(n);
    char hi = 'a', one_hi = 'a';
    for (int i = 0; i < n; ++i) {
      if (s[i] < hi) {
        ans[i] = 1;
        if (s[i] < one_hi) {
          cout << "NO";
          return;
        }
        one_hi = max(one_hi, s[i]);
      }
      hi = max(hi, s[i]);
    }
    cout << "YES" << endl;
    for (int i : ans)
      cout << i;
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}