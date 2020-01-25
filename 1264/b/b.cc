#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

class Solution {
  int a, b, c, d;
  bool solved = false;
  deque<int> ans;

  void assign() {
    for (int i = 0; i < a - 1; ++i) {
      ans.emplace_back(0);
      ans.emplace_back(1);
      b--;
    }
    if (a > 0)
      ans.emplace_back(0);
    if (b < 0)
      return;
    for (int i = 0; i < b - 1; ++i) {
      ans.emplace_back(1);
      ans.emplace_back(2);
      c--;
    }
    if (b > 0)
      ans.emplace_back(1);

    if (c < 0) {
      ans.pop_back();
      ans.pop_back();
      ans.emplace_front(1);
      c++;
    }
    if (c < 0)
      return;
    if (d > c + 1 || c > d + 2)
      return;

    if (d > c) {
      if (!ans.empty() && ans.back() == 1) {
        ans.pop_back();
        ans.emplace_front(1);
      }
      for (int i = 0; i < c; ++i) {
        ans.emplace_back(3);
        ans.emplace_back(2);
      }
      if (d == c + 1)
        ans.emplace_back(3);
    } else {
      if (c == d + 2)
        ans.emplace_front(2);

      for (int i = 0; i < d; ++i) {
        ans.emplace_back(2);
        ans.emplace_back(3);
      }
      if (c > d)
        ans.emplace_back(2);
    }

    solved = true;
    for (int i = 0; i < ans.size() - 1; ++i) {
      if (abs(ans[i] - ans[i + 1]) != 1) {
        solved = false;
        break;
      }
    }
  }

public:
  void solve() {
    cin >> a >> b >> c >> d;

    assign();

    if (!solved)
      cout << "NO";
    else {
      cout << "YES" << endl;
      for (int i : ans)
        cout << i << " ";
    }
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}