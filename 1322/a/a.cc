#include <iostream>

using namespace std;

class Solution {
public:
  void solve() {
    int n;
    string s;
    cin >> n >> s;
    int depth = 0, ans = 0, l = 0;
    for (char c : s) {
      if (c == '(') {
        if (depth < 0)
          ans++;
        depth++;
      } else {
        depth--;
        if (depth < 0)
          ans++;
      }
    }
    cout << (depth == 0 ? ans : -1);
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}