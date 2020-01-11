#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class UnionFind {
  vector<int> f, s;

public:
  UnionFind(int n) {
    f = vector<int>(n);
    for (int i = 0; i < n; ++i)
      f[i] = i;
    s = vector<int>(n, 1);
  }

  int find(int a) {
    if (f[a] == a)
      return a;
    else
      return f[a] = find(f[a]);
  }

  void connect(int a, int b) {
    int fa = find(a);
    int fb = find(b);
    if (fa == fb)
      return;
    if (s[fa] < s[fb]) {
      f[fa] = fb;
      s[fb] += s[fa];
    } else {
      f[fb] = fa;
      s[fa] += s[fb];
    }
  }

  int solve() {
    for (int i = 0; i < f.size(); ++i)
      find(i);
    unordered_map<int, pair<int, int>> dict;
    for (int i = 0; i < f.size(); ++i) {
      if (dict.find(f[i]) == dict.end())
        dict[f[i]] = make_pair(i, i);
      else {
        dict[f[i]].first = min(dict[f[i]].first, i);
        dict[f[i]].second = max(dict[f[i]].second, i);
      }
    }
    vector<pair<int, int>> intervals;
    for (const auto &p : dict)
      intervals.emplace_back(p.second);
    sort(intervals.begin(), intervals.end());
    int ans = 0;
    int right = -1;
    for (int i = 0; i < intervals.size(); ++i) {
      if (intervals[i].first < right)
        ans++;
      right = max(right, intervals[i].second);
    }
    return ans;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  UnionFind uf = UnionFind(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    uf.connect(a - 1, b - 1);
  }
  cout << uf.solve();
  return 0;
}