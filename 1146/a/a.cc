#include <iostream>

using namespace std;

class Solution {
 public:
  void solve() {
    string s;
    cin >> s;
    int cnt = 0, len = s.size();
    for (char c : s) cnt += c == 'a';
    cout << min(len, cnt * 2 - 1);
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}