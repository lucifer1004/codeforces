#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define INF 0x3f3f3f3f
#define MOD 1000000007

using namespace std;
typedef long long ll;

string modify(string &s, int k) {
  int n = s.size();
  string left = s.substr(k - 1, n - k + 1);
  string right = s.substr(0, k - 1);
  if ((n - k) % 2 == 0)
    reverse(right.begin(), right.end());
  return left + right;
}

class Solution {
public:
  void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v;
    char lo = 'z';
    for (int i = 0; i < n; ++i) {
      char c = s[i];
      if (c == lo)
        v.emplace_back(i);
      else if (c < lo) {
        v.clear();
        v.emplace_back(i);
        lo = c;
      }
    }
    vector<pair<string, int>> t;
    for (int i : v)
      t.emplace_back(modify(s, i + 1), i + 1);
    int ans = 1;
    string result = s;
    for (auto p : t) {
      if (p.first < result) {
        result = p.first;
        ans = p.second;
      }
    }
    cout << result << endl;
    cout << ans << endl;
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