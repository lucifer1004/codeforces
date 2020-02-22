#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  vector<ll> sum(n);
  sum[0] = a[0];
  for (int i = 1; i < n; ++i)
    sum[i] = sum[i - 1] + a[i];
  if (sum[n - 1] == 1) {
    printf("-1");
    return 0;
  }
  vector<int> primes = {2, 3, 5, 7, 11, 13};
  for (int i = 8; i < 500001; ++i) {
    int k = i * 2 + 1;
    int j = 0;
    bool isPrime = true;
    while (primes[j] * primes[j] <= k) {
      if (k % primes[j] == 0) {
        isPrime = false;
        break;
      }
      j++;
    }
    if (isPrime)
      primes.emplace_back(k);
  }
  ll ans = LLONG_MAX;
  ll rest = sum[n - 1];
  for (int prime : primes) {
    if (rest % prime == 0) {
      ll curr = 0;
      for (ll s : sum) {
        ll rem = s % prime;
        curr += min(rem, prime - rem);
      }
      ans = min(ans, curr);
      while (rest % prime == 0)
        rest /= prime;
    }
    if (prime * prime >= rest)
      break;
  }
  if (rest != 1) {
    ll curr = 0;
    for (ll s : sum) {
      ll rem = s % rest;
      curr += min(rem, rest - rem);
    }
    ans = min(ans, curr);
  }
  printf("%lld", ans);
}