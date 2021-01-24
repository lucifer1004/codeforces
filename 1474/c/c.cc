#include <iostream>
#include <map>
#include <vector>

using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n * 2; ++i) {
      int a;
      cin >> a;
      cnt[a]++;
    }
    int hi = cnt.rbegin()->first;
    bool found = false;
    for (auto [i, freq] : cnt) {
      map<int, int> now(cnt);
      if (i == hi && freq < 2)
        continue;
      vector<pair<int, int>> ops{{hi, i}};
      now[hi]--;
      now[i]--;
      if (now[hi] == 0)
        now.erase(hi);
      if (now.count(i) && now[i] == 0)
        now.erase(i);
      bool valid = true;
      int last = hi;
      for (int j = 0; j < n - 1; ++j) {
        int chi = now.rbegin()->first;
        if (chi >= last || !now.count(last - chi) ||
            (last == chi * 2 && now[chi] < 2)) {
          valid = false;
          break;
        }
        now[chi]--;
        now[last - chi]--;
        ops.emplace_back(chi, last - chi);
        if (now[chi] == 0)
          now.erase(chi);
        if (now.count(last - chi) && now[last - chi] == 0)
          now.erase(last - chi);
        last = chi;
      }
      if (valid) {
        found = true;
        cout << "YES" << endl;
        cout << hi + i << endl;
        for (auto [l, r] : ops)
          cout << l << " " << r << endl;
        break;
      }
    }
    if (!found)
      cout << "NO" << endl;
  }
}