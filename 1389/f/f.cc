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
typedef long long ll;

mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }

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

struct Segment {
  int l, r, t;
  bool operator<(const Segment &other) const {
    return r > other.r || (r == other.r && l > other.l);
  }
};

class Solution {
public:
  void solve() {
    int n;
    read(n);
    vector<Segment> e(n);
    set<int> s;
    for (int i = 0; i < n; ++i) {
      read(e[i].l), read(e[i].r), read(e[i].t);
      s.insert(e[i].l), s.insert(e[i].r);
    }
    sort(e.begin(), e.end());
    vector<int> vs(s.begin(), s.end());
    int m = vs.size();
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  read(t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}