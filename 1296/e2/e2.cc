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
    string hi = "a";
    for (int i = 0; i < n; ++i) {
      int j = 0;
      while (j < hi.size() && s[i] < hi[j])
        j++;
      if (j == hi.size())
        hi.push_back(s[i]);
      hi[j] = max(hi[j], s[i]);
      ans[i] = j + 1;
    }
    cout << hi.size() << endl;
    for (int i = 0; i < n; ++i)
      cout << ans[i] << " ";
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}