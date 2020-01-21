#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
  void solve() {
    string command;
    cin >> command;
    map<char, int> cnt;
    for (char c : command) {
      cnt[c]++;
    }
    int lr = min(cnt['L'], cnt['R']);
    int ud = min(cnt['U'], cnt['D']);
    if (lr == 0)
      ud = min(ud, 1);
    if (ud == 0)
      lr = min(lr, 1);
    cout << 2 * (lr + ud) << endl;
    for (int i = 0; i < lr; ++i)
      cout << "L";
    for (int i = 0; i < ud; ++i)
      cout << "U";
    for (int i = 0; i < lr; ++i)
      cout << "R";
    for (int i = 0; i < ud; ++i)
      cout << "D";
    cout << endl;
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