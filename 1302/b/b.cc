#include <bitset>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#define BLOCK 1024

using namespace std;
typedef long long ll;

class Solution {
  vector<int> in, cnt;
  vector<bitset<BLOCK>> bs;
  vector<vector<int>> from;

public:
  void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    in = vector<int>(n);
    cnt = vector<int>(n);
    bs = vector<bitset<BLOCK>>(n);
    from = vector<vector<int>>(n);
    for (int i = 0; i < m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      from[v - 1].emplace_back(u - 1);
      in[u - 1]++;
    }
    queue<int> q;
    vector<int> topo;
    for (int i = 0; i < n; ++i)
      if (in[i] == 0)
        q.push(i);
    while (!q.empty()) {
      int f = q.front();
      q.pop();
      topo.emplace_back(f);
      for (int j : from[f]) {
        in[j]--;
        if (in[j] == 0)
          q.push(j);
      }
    }

    for (int k = 0; k * BLOCK < n; ++k) {
      for (int i = n - 1; i >= 0; --i) {
        int idx = topo[i];
        bs[idx].reset();
        if (idx / BLOCK == k)
          bs[idx].set(idx % BLOCK);
        for (int j : from[idx])
          bs[idx] |= bs[j];
        cnt[idx] += bs[idx].count();
      }
    }

    ll ans = 0;
    for (ll i : cnt)
      ans += i * i;

    printf("%lld", ans);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}