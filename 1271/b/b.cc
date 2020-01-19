#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
public:
  void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int white = 0, black = 0;
    for (char c : s) {
      white += c == 'W';
    }
    black = n - white;
    if (n % 2 == 0 && white % 2 == 1) {
      cout << -1;
      return;
    }

    vector<int> op;
    if (white % 2 == 0) {
      // Change all to black
      for (int i = 0; i < n - 1; ++i) {
        if (s[i] == 'W') {
          op.push_back(i + 1);
          s[i] = 'B';
          s[i + 1] = s[i + 1] == 'B' ? 'W' : 'B';
        }
      }
    } else {
      // Change all to white
      for (int i = 0; i < n - 1; ++i) {
        if (s[i] == 'B') {
          op.push_back(i + 1);
          s[i] = 'W';
          s[i + 1] = s[i + 1] == 'B' ? 'W' : 'B';
        }
      }
    }

    cout << op.size() << endl;
    for (int i : op)
      cout << i << " ";
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}