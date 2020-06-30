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

class Solution {
public:
  void solve() {
    int n, k;
    read(n), read(k);
    vector<int> first(n + 1), last(n + 1);
    for (int i = 0; i < k; ++i) {
      int a;
      read(a);
      if (!first[a])
        first[a] = i + 1;
      last[a] = i + 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = max(1, i - 1); j <= min(i + 1, n); ++j) {
        if (i == j && !first[i])
          ans++;
        if (i != j && (!first[i] || !first[j] || last[j] < first[i]))
          ans++;
      }
    cout << ans;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}