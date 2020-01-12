#include <algorithm>
#include <bitset>
#include <climits>
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

class Solution {
  bool left;

  void display(string s, int l) {
    int n = s.size();
    int rest = l - n;
    int lb, rb;
    if (rest % 2 == 0) {
      lb = rb = rest / 2;
    } else {
      if (left) {
        lb = rest / 2;
        rb = rest - lb;
      } else {
        rb = rest / 2;
        lb = rest - rb;
      }
      left = !left;
    }
    cout << '*';
    for (int i = 0; i < lb; ++i) cout << ' ';
    cout << s;
    for (int i = 0; i < rb; ++i) cout << ' ';
    cout << '*' << endl;
  }

 public:
  void solve() {
    string line;
    vector<string> lines;
    int max_len = 0;
    while (getline(cin, line)) {
      lines.push_back(line);
      max_len = max(max_len, (int)line.size());
    }
    for (int i = 0; i < max_len + 2; i++) cout << '*';
    cout << endl;
    left = true;
    for (string line : lines) display(line, max_len);
    for (int i = 0; i < max_len + 2; i++) cout << '*';
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}