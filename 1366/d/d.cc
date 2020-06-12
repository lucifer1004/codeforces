#include <cstdio>
#include <map>
#include <vector>
#define MAXN 10000005

using namespace std;
int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }
int main() {
  vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
  for (int i = 23; i * i < MAXN; i += 2) {
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
  int n;
  map<int, pair<int, int>> memo;
  scanf("%d", &n);
  vector<pair<int, int>> ans;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    if (memo.count(a)) {
      ans.push_back(memo[a]);
      continue;
    }
    int a0 = a;
    pair<int, int> p = {-1, -1};
    for (int j = 0; primes[j] * primes[j] <= a; ++j) {
      if (a % primes[j] == 0) {
        while (a % primes[j] == 0)
          a /= primes[j];
        if (a != 1)
          p = {primes[j], a};
        break;
      }
    }
    ans.push_back(p);
    memo[a0] = p;
  }
  for (int i = 0; i < n; ++i)
    printf("%d ", ans[i].first);
  printf("\n");
  for (int i = 0; i < n; ++i)
    printf("%d ", ans[i].second);
}