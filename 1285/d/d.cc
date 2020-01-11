#include <algorithm>
#include <bitset>
#include <climits>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long ll;
typedef bitset<32> bs;

const int MAX = 100005;

class Solution {
  vector<bs> a;

  int rec(int d, unordered_set<int> &ids) {
    if (ids.empty()) return INT_MAX;
    if (d == -1) return 0;

    unordered_set<int> ones, zeros;
    for (int id : ids) {
      if (a[id][d])
        ones.insert(id);
      else
        zeros.insert(id);
    }

    int one = rec(d - 1, ones);
    int zero = rec(d - 1, zeros);
    if (ones.empty()) return zero;
    if (zeros.empty()) return one;
    return min(zero, one) + (1 << d);
  }

 public:
  void solve() {
    int n;
    cin >> n;

    a = vector<bs>(n);
    for (int i = 0; i < n; ++i) {
      int ai;
      cin >> ai;
      a[i] = bs(ai);
    }

    unordered_set<int> ids;
    for (int i = 0; i < n; ++i) ids.insert(i);
    cout << rec(31, ids);
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}