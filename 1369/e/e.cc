#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

template <typename T> void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-')
      sig = -1;
  for (; isdigit(c); c = getchar())
    x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

class Solution {
public:
  void solve() {
    int n, m;
    read(n), read(m);
    vector<int> w(n + 1);
    for (int i = 1; i <= n; ++i)
      read(w[i]);
    vector<unordered_set<int>> need(n + 1);
    vector<int> people(m + 1);
    vector<bool> mark(m + 1);
    vector<pair<int, int>> p;
    for (int i = 1; i <= m; ++i) {
      int x, y;
      read(x), read(y);
      people[i] = x + y;
      need[x].insert(i);
      need[y].insert(i);
    }
    vector<int> extra(n + 1);
    set<pair<int, int>> pq;
    for (int i = 1; i <= n; ++i) {
      extra[i] = need[i].size() - w[i];
      pq.insert({extra[i], i});
    }
    vector<int> ans;
    while (!pq.empty()) {
      int i = pq.begin()->second;
      pq.erase(pq.begin());
      if (extra[i] > 0) {
        cout << "DEAD";
        exit(0);
      }
      for (int j : need[i]) {
        int other = people[j] - i;
        pq.erase({extra[other], other});
        need[other].erase(j);
        extra[other]--;
        ans.emplace_back(j);
        pq.insert({extra[other], other});
      }
    }
    reverse(ans.begin(), ans.end());
    cout << "ALIVE" << endl;
    for (int i : ans)
      cout << i << " ";
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}