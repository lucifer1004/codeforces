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

class Solution {
public:
  void solve() {
    int n;
    scanf("%d", &n);
    vector<ll> a(n);
    ll last = 0;
    for (int i = 1; i < n; i += 2) {
      scanf("%lld", &a[i]);
      bool found = false;
      for (int j = sqrt(a[i]); j >= 1; --j) {
        if (a[i] % j == 0) {
          ll k = a[i] / j;
          if ((j + k) & 1)
            continue;
          ll p = (j + k) / 2;
          ll q = abs(j - k) / 2;
          if (p > q)
            swap(p, q);
          if (p <= last)
            continue;
          a[i - 1] = p * p - last * last;
          last = q;
          found = true;
          break;
        }
      }
      if (!found) {
        printf("No");
        return;
      }
    }
    printf("Yes\n");
    for (ll i : a)
      printf("%lld ", i);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}