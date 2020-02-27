#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define INF 0x3f3f3f3f
#define MOD 1000000007

using namespace std;
const double eps = 1e-8;

mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }

class Solution {
  double expectation(int start, vector<int> &adj) {
    vector<double> p(101);
    p[start] = 1;
    double e = 0;
    for (int turn = 1; turn <= 200; ++turn) {
      vector<double> np(101);
      for (int j = start; j <= 99; ++j)
        for (int dice = 1; dice <= 6; ++dice) {
          int idx = j + dice;
          if (idx <= 100) {
            if (adj[idx] != 0)
              idx = adj[idx];
            np[idx] += p[j] / 6;
          } else
            np[j] += p[j] / 6;
        }
      swap(np, p);
      e += p[100] * turn;
    }
    return e;
  }

public:
  void solve() {
    vector<int> adj(101);
    for (int i = 0; i < 10; ++i)
      for (int j = 0; j < 10; ++j) {
        int delta = i % 2 == 0 ? j : 9 - j;
        int idx = 100 - i * 10 - delta;
        int ladder;
        scanf("%d", &ladder);
        if (ladder != 0) {
          int ni = i - ladder;
          if (ni >= 0) {
            int ndelta = ni % 2 == 0 ? j : 9 - j;
            int nidx = 100 - ni * 10 - ndelta;
            adj[idx] = nidx;
          }
        }
      }
    for (int i = 90; i >= 1; --i) {
      if (adj[i] == 0)
        continue;
      double e1 = expectation(i, adj);
      double e2 = expectation(adj[i], adj);
      if (e2 - e1 > eps)
        adj[i] = 0;
    }

    printf("%.10f", expectation(1, adj));
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}