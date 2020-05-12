#include <iostream>
#include <queue>
#include <vector>
#define MAXN 200005

using namespace std;
typedef long long ll;
int main() {
  int n;
  cin >> n;
  vector<priority_queue<int, vector<int>, greater<>>> f(MAXN);
  vector<int> primes = {2, 3, 5, 7, 11, 13};
  for (int i = 17; i < MAXN; i += 2) {
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

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    for (int j = 0; primes[j] * primes[j] <= a; ++j) {
      int cnt = 0;
      while (a % primes[j] == 0) {
        a /= primes[j];
        cnt++;
      }
      if (cnt > 0)
        f[primes[j]].push(cnt);
    }
    if (a != 0)
      f[a].push(1);
  }

  ll ans = 1;
  for (int prime : primes) {
    if (f[prime].size() <= n - 2)
      continue;
    if (f[prime].size() == n)
      f[prime].pop();
    int a = f[prime].top();
    for (int i = 0; i < a; ++i)
      ans *= prime;
  }
  cout << ans;
}