#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#define INF 0x3f3f3f3f

using namespace std;
using ll = int64_t;

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

vector<int> primes = {2, 3, 5, 7, 11, 13};

class Solution {
public:
  void solve() {
    int n;
    read(n);
    vector<int> p;
    int k = n;
    for (int j = 0; primes[j] * primes[j] <= k; ++j) {
      if (k % primes[j] == 0) {
        p.emplace_back(primes[j]);
        while (k % primes[j] == 0)
          k /= primes[j];
      }
    }
    if (k != 1)
      p.emplace_back(k);
    set<int> factors;
    for (int j = 2; j * j <= n; ++j) {
      if (n % j == 0)
        factors.insert(j), factors.insert(n / j);
    }
    factors.insert(n);
    int pp = p.size();
    if (pp == 1) {
      for (int factor : factors)
        printf("%d ", factor);
      printf("\n0\n");
      return;
    }
    vector<set<int>> vf(pp);
    for (int factor : factors) {
      for (int i = 0; i < pp; ++i)
        if (factor % p[i] == 0)
          vf[i].insert(factor);
    }
    if (pp == 2) {
      if (p[0] * p[1] == n)
        printf("%d %d %d\n1\n", p[0], p[1], n);
      else {
        printf("%d ", p[0]);
        factors.erase(p[0]);
        vf[0].erase(p[0]);
        int reserve = 0;
        ll a = (ll)p[0] * p[0] * p[1];
        ll b = (ll)p[0] * p[1] * p[1];
        if (a < INF && factors.count(a))
          reserve = a;
        else if (b < INF && factors.count(b))
          reserve = b;
        factors.erase(reserve);
        vf[0].erase(reserve);
        for (int i : vf[0])
          if (i != p[0] * p[1]) {
            factors.erase(i);
            vf[1].erase(i);
            printf("%d ", i);
          }
        printf("%d %d ", p[0] * p[1], p[1]);
        factors.erase(p[0] * p[1]);
        factors.erase(p[1]);
        for (int factor : factors)
          printf("%d ", factor);
        printf("%d\n0\n", reserve);
      }
    } else {
      vf[0].erase(p[0] * p[pp - 1]);
      for (int i = 0; i < pp; ++i) {
        printf("%d ", p[i]);
        int nxt = (i + 1) % pp;
        vf[i].erase(p[i]);
        factors.erase(p[i]);
        for (int k : vf[i]) {
          if (k != p[i] * p[nxt]) {
            printf("%d ", k);
            factors.erase(k);
            for (int j = i + 1; j < pp; ++j) {
              vf[j].erase(k);
            }
          }
        }
        printf("%d ", p[i] * p[nxt]);
        vf[nxt].erase(p[i] * p[nxt]);
        factors.erase(p[i] * p[nxt]);
      }
      for (int factor : factors)
        printf("%d ", factor);
      printf("\n0\n");
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 17; i <= 35000; i += 2) {
    bool is_prime = true;
    for (int j = 0; primes[j] * primes[j] <= i; ++j) {
      if (i % primes[j] == 0) {
        is_prime = false;
        break;
      }
    }
    if (is_prime)
      primes.emplace_back(i);
  }
  int t;
  read(t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}