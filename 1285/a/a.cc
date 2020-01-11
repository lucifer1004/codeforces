#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

class Solution {
 public:
  void solve() {
    int n;
    cin >> n;
    string command;
    cin >> command;
    int l = 0, r = 0;
    for (const char c : command) {
      if (c == 'L')
        l++;
      else
        r++;
    }
    cout << l + r + 1;
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}