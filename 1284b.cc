#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

void solve() {
  int n;
  cin >> n;

  vector<int> lo(n), hi(n), h;
  vector<bool> self(n);

  for (int i = 0; i < n; ++i) {
    int l;
    cin >> l;
    lo[i] = INT_MAX;
    hi[i] = INT_MIN;
    for (int j = 0; j < l; ++j) {
      int s;
      cin >> s;
      if (s > lo[i]) self[i] = true;
      lo[i] = min(lo[i], s);
      hi[i] = max(hi[i], s);
    }
    if (!self[i]) h.push_back(hi[i]);
  }

  ll r = h.size();
  sort(h.begin(), h.end());

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    if (self[i])
      ans += n;
    else {
      ans += n - r;
      ans += (int)(h.end() - upper_bound(h.begin(), h.end(), lo[i]));
    }
  }

  cout << ans;
}

int main() { solve(); }