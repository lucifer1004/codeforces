#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
  int n, m;
  vector<int> a, lo, hi, last_front;

  int lowbit(int x) { return x & -x; }

  void update(int idx, int d) {
    for (; idx <= n + m; idx += lowbit(idx)) {
      a[idx] += d;
    }
  }

  int query(int idx) {
    int ans = 0;
    for (; idx > 0; idx -= lowbit(idx)) {
      ans += a[idx];
    }
    return ans;
  }

 public:
  void solve() {
    cin >> n >> m;
    a = vector<int>(n + m + 1);
    lo = vector<int>(n + 1);
    hi = vector<int>(n + 1);
    last_front = vector<int>(n + 1);

    // Initialize
    for (int i = 1; i <= n; ++i) {
      lo[i] = i;
      hi[i] = i;
      last_front[i] = n - i + 1;
      update(i, 1);
    }

    // Processing
    for (int i = 1; i <= m; ++i) {
      int msg;
      cin >> msg;
      lo[msg] = 1;
      hi[msg] = max(hi[msg], query(n + i) - query(last_front[msg] - 1));
      update(last_front[msg], -1);
      update(n + i, 1);
      last_front[msg] = n + i;
    }

    // Update: query all indices again
    for (int i = 1; i <= n; ++i) {
      hi[i] = max(hi[i], query(n + m) - query(last_front[i] - 1));
    }

    // Output
    for (int i = 1; i <= n; ++i) cout << lo[i] << " " << hi[i] << endl;
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}