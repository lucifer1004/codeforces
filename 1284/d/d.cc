#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  int t;

  static void normalize(vector<int> &a, unordered_map<int, int> &d) {
    for (int &i : a)
      i = d[i];
  }

  bool check(vector<int> &sa, vector<int> &ea, vector<int> &sb,
             vector<int> &eb) {
    vector<set<int>> start(t), end(t);
    for (int i = 0; i < sa.size(); ++i) {
      start[sa[i]].insert(i);
      end[ea[i]].insert(i);
    }
    map<int, int> startb, endb;
    for (int i = 0; i < t; ++i) {
      for (int j : start[i]) {
        if (!startb.empty()) {
          int last_start = prev(startb.end())->first;
          int first_end = endb.begin()->first;
          if (sb[j] > first_end || eb[j] < last_start)
            return false;
        }
        startb[sb[j]]++;
        endb[eb[j]]++;
      }

      for (int j : end[i]) {
        startb[sb[j]]--;
        if (startb[sb[j]] == 0)
          startb.erase(sb[j]);
        endb[eb[j]]--;
        if (endb[eb[j]] == 0)
          endb.erase(eb[j]);
      }
    }

    return true;
  }

public:
  void solve() {
    int n;
    scanf("%d", &n);
    vector<int> sa(n), ea(n), sb(n), eb(n);
    set<int> time;
    for (int i = 0; i < n; ++i) {
      scanf("%d%d%d%d", &sa[i], &ea[i], &sb[i], &eb[i]);
      time.insert(sa[i]);
      time.insert(sb[i]);
      time.insert(ea[i]);
      time.insert(eb[i]);
    }
    t = time.size();
    unordered_map<int, int> dict;
    int idx = 0;
    for (int i : time)
      dict[i] = idx++;
    normalize(sa, dict);
    normalize(sb, dict);
    normalize(ea, dict);
    normalize(eb, dict);

    bool ab = check(sa, ea, sb, eb);
    if (!ab) {
      printf("NO");
      return;
    }
    bool ba = check(sb, eb, sa, ea);
    if (!ba)
      printf("NO");
    else
      printf("YES");
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}