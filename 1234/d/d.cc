#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
typedef long long ll;

class Segment {
  int n;
  string s;
  unordered_map<char, vector<int>> dict;

  int lowbit(int x) { return x & (-x); }

  void update(char c, int i, int x) {
    while (i <= n) {
      dict[c][i] += x;
      i += lowbit(i);
    }
  }

  int sum(char c, int x) {
    int sum = 0;
    while (x > 0) {
      sum += dict[c][x];
      x -= lowbit(x);
    }
    return sum;
  }

 public:
  Segment(string s) {
    n = s.size();
    this->s = s;
    for (char c = 'a'; c <= 'z'; ++c) dict[c] = vector<int>(n + 5);
    for (int i = 0; i < n; ++i) {
      update(s[i], i + 1, 1);
    }
  }

  void modify(int i, char c) {
    update(s[i - 1], i, -1);
    update(c, i, 1);
    s[i - 1] = c;
  }

  void query(int l, int r) {
    int ans = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
      ans += (sum(c, r) - sum(c, l - 1) > 0);
    }
    cout << ans << endl;
  }
};

class Solution {
 public:
  void solve() {
    string s;
    cin >> s;
    int q;
    cin >> q;
    Segment seg = Segment(s);

    for (int i = 0; i < q; ++i) {
      int type;
      cin >> type;
      if (type == 1) {
        int idx;
        char c;
        cin >> idx >> c;
        seg.modify(idx, c);
      } else {
        int l, r;
        cin >> l >> r;
        seg.query(l, r);
      }
    }
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}