#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
 public:
  void solve() {
    int n;
    cin >> n;
    unordered_map<ll, ll> begin_with, end_with;
    set<ll> mark;
    for (int i = 0; i < n; ++i) {
      ll l, r;
      cin >> l >> r;
      mark.insert(l);
      mark.insert(r);
      begin_with[l]++;
      end_with[r]++;
    }

    vector<ll> cnt(n + 1);
    ll current = 0, last = -1;
    for (ll pos : mark) {
      if (last != -1) {
        cnt[current] += pos - last - 1;
      }
      last = pos;
      cnt[current + begin_with[pos]]++;
      current += begin_with[pos] - end_with[pos];
    }

    for (int i = 1; i <= n; ++i) cout << cnt[i] << " ";
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}