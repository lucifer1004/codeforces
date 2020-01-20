#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long ll;

set<string> ok = {"0000", "1000", "0100", "0010", "0001", "0011", "1100"};

class Solution {
  int n, q, blocked;
  vector<vector<int>> state;

  string join(int a, int b, int c, int d) {
    return to_string(a) + to_string(b) + to_string(c) + to_string(d);
  }

  void update(int r, int c) {

    if (c > 1) {
      string s =
          join(state[0][c - 1], state[0][c], state[1][c - 1], state[1][c]);
      bool is_blocked_before = ok.find(s) == ok.end();
      state[r][c] = 1 - state[r][c];
      s = join(state[0][c - 1], state[0][c], state[1][c - 1], state[1][c]);
      bool is_blocked_after = ok.find(s) == ok.end();
      blocked += is_blocked_after - is_blocked_before;
    }

    if (c < n) {
      if (c > 1)
        state[r][c] = 1 - state[r][c];
      string s =
          join(state[0][c], state[0][c + 1], state[1][c], state[1][c + 1]);
      bool is_blocked_before = ok.find(s) == ok.end();
      state[r][c] = 1 - state[r][c];
      s = join(state[0][c], state[0][c + 1], state[1][c], state[1][c + 1]);
      bool is_blocked_after = ok.find(s) == ok.end();
      blocked += is_blocked_after - is_blocked_before;
    }
  }

public:
  void solve() {
    cin >> n >> q;
    state = vector<vector<int>>(2, vector<int>(n + 1));
    blocked = 0;
    for (int i = 0; i < q; ++i) {
      int r, c;
      cin >> r >> c;
      update(r - 1, c);
      cout << (blocked == 0 ? "Yes" : "No") << endl;
    }
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}