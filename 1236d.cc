#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  vector<set<int>> row(n + 1), col(m + 1);
  vector<set<int, greater<>>> row2(n + 1), col2(m + 1);
  for (int i = 0; i < k; ++i) {
    int a, b;
    cin >> a >> b;
    row[a].insert(b);
    col[b].insert(a);
    row2[a].insert(b);
    col2[b].insert(a);
  }
  int direction = 0;
  ll steps = 1;
  int left = 1, right = m, top = 2, bottom = n;
  int r = 1, c = 1;
  bool moved = true;
  while (moved || (steps == 1 && direction == 1)) {
    moved = false;
    if (direction == 0) {
      int rlimit = right;
      if (!row[r].empty()) {
        auto it = row[r].lower_bound(c);
        if (it != row[r].end())
          rlimit = min(rlimit, *it - 1);
      }
      if (rlimit > c)
        moved = true;
      steps += rlimit - c;
      c = rlimit;
      right = rlimit - 1;
    } else if (direction == 1) {
      int blimit = bottom;
      if (!col[c].empty()) {
        auto it = col[c].lower_bound(r);
        if (it != col[c].end())
          blimit = min(blimit, *it - 1);
      }
      if (blimit > r)
        moved = true;
      steps += blimit - r;
      r = blimit;
      bottom = blimit - 1;
    } else if (direction == 2) {
      int llimit = left;
      if (!row2[r].empty()) {
        auto it = row2[r].lower_bound(c);
        if (it != row2[r].end())
          llimit = max(llimit, *it + 1);
      }
      if (llimit < c)
        moved = true;
      steps += c - llimit;
      c = llimit;
      left = llimit + 1;
    } else {
      int tlimit = top;
      if (!col2[c].empty()) {
        auto it = col2[c].lower_bound(r);
        if (it != col2[c].end())
          tlimit = max(tlimit, *it + 1);
      }
      if (tlimit < r)
        moved = true;
      steps += r - tlimit;
      r = tlimit;
      top = tlimit + 1;
    }
    direction = (direction + 1) % 4;
  }
  if (steps + k == n * m)
    cout << "Yes";
  else
    cout << "No";
}