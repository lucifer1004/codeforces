#include <algorithm>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
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
using ll = long long;

mt19937 rng(random_device{}());
mt19937_64 rng64(random_device{}());

template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-') sig = -1;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

class Solution {
 public:
  void solve() {
    int n, k;
    read(n), read(k);
    map<int, int> cnt;
    while (n--) {
      int x;
      read(x);
      cnt[x]++;
    }

    int last = -1, ans = 0, l = 0, r = 0, acc = 0;
    for (auto [key, freq] : cnt) {
      if (freq < k) {
        acc = 0;
      } else if (key == last + 1) {
        acc++;
      } else {
        acc = 1;
      }

      if (acc > ans) {
        ans = acc;
        r = key;
        l = key - acc + 1;
      }

      last = key;
    }

    if (ans == 0) {
      printf("-1\n");
    } else {
      printf("%d %d\n", l, r);
    }
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