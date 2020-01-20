#include <iostream>

using namespace std;

class Solution {
 public:
  void solve() {
    string s;
    cin >> s;
    string t;
    for (char c : s) {
      if (c != 'a') t += c;
    }
    int len = t.size();
    if (len % 2 != 0) {
      cout << ":(";
      return;
    }
    string tail = t.substr(0, len / 2);
    string raw_tail = s.substr((int)s.size() - len / 2, len / 2);
    if (tail == raw_tail) {
      cout << s.substr(0, (int)s.size() - len / 2);
    } else {
      cout << ":(";
    }
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}