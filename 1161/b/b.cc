#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PRIME 71

using namespace std;
typedef long long ll;

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
    vector<vector<int>> adj(n + 1);
    vector<int> l(n + 1), r(n + 1);
    for (int i = 0; i < m; ++i) {
      int u, v;
      read(u), read(v);
      adj[u].emplace_back(v), adj[v].emplace_back(u);
    }
    for (int i = 1; i <= n; ++i) {
      if (adj[i].empty())
        continue;
      for (int &j : adj[i])
        if (j < i)
          j += n;
      sort(adj[i].begin(), adj[i].end());
      ll lcode = 0, rcode = 0;
      for (auto it = adj[i].begin(); it != adj[i].end(); ++it)
        lcode = (lcode * PRIME + (*it - i)) % MOD;
      for (auto it = adj[i].rbegin(); it != adj[i].rend(); ++it)
        rcode = (rcode * PRIME + (n + i - *it)) % MOD;
      l[i] = lcode, r[i] = rcode;
    }
    for (int i = 1; i < n; ++i) {
      if (n % i != 0)
        continue;
      bool ok = true;
      for (int j = 1; j <= n; ++j) {
        int nxt = (j + i - 1) % n + 1;
        if (l[j] != l[nxt] && l[j] != r[nxt]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        printf("Yes");
        exit(0);
      }
    }
    printf("No");
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}