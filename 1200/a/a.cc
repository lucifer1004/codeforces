#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
 public:
  void solve() {
    int n;
    cin >> n;
    string seq;
    cin >> seq;
    vector<bool> rooms(10);
    for (char c : seq) {
      if (c == 'L') {
        int i = 0;
        while (rooms[i]) i++;
        rooms[i] = true;
      } else if (c == 'R') {
        int i = 9;
        while (rooms[i]) i--;
        rooms[i] = true;
      } else
        rooms[c - '0'] = false;
    }
    for (int state : rooms) cout << state;
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}