#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

class Solution {
 public:
  void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), p(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      p[i] = a[i] - (i == 0 ? 0 : a[i - 1]);
    }

    // Add last period.
    p.push_back(m - a[n - 1]);

    ll lon = 0, loff = 0, ron = 0, roff = 0;
    for (int i = 0; i < p.size(); ++i) {
      if (i % 2 == 0)
        ron += p[i];
      else
        roff += p[i];
    }
    ll maxon = ron;
    for (int i = 0; i < p.size(); ++i) {
      if (i % 2 == 0) {
        // Current period is on.
        if (p[i] == 1) {
          // Cannot insert into this period.
          lon += 1;
          ron -= 1;
        } else {
          ron -= p[i];
          ll newon = lon + p[i] - 1 + ron;
          maxon = max(maxon, newon);
          lon += p[i];
        }
      } else {
        // Current period is off.
        if (p[i] == 1) {
          // Cannot insert into this period.
          loff += 1;
          roff -= 1;
        } else {
          roff -= p[i];
          ll newon = lon + p[i] - 1 + roff;
          maxon = max(maxon, newon);
          loff += p[i];
        }
      }
    }

    cout << maxon;
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}