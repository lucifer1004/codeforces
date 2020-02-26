#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
#define MAXN 100005
#define INF 1e10 + 5

using namespace std;
typedef long long ll;

ll fexp(ll x, ll y) {
  ll ans = 1;
  while (y > 0) {
    if (y & 1)
      ans *= x;
    x *= x;
    if (x > INF)
      return INF + 1;
    y >>= 1;
  }
  return ans;
}

class Solution {

public:
  void solve() {
    vector<int> primes = {2, 3, 5, 7, 11, 13};
    for (int i = 17; i * i <= MAXN; i += 2) {
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

    int n, k;
    scanf("%d%d", &n, &k);
    vector<ll> coeff = {1};
    for (int i = 2; i < MAXN; ++i) {
      ll val = fexp(i, k);
      if (val > INF)
        break;
      coeff.emplace_back(val);
    }

    unordered_map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
      int a;
      scanf("%d", &a);
      cnt[a]++;
    }

    if (k <= 3) {
      unordered_map<int, unordered_map<int, int>> factor;
      for (const auto &p : cnt) {
        int num = p.first;
        for (int prime : primes) {
          while (num % prime == 0) {
            num /= prime;
            factor[p.first][prime]++;
          }
          if (prime * prime >= num)
            break;
        }
        if (num != 1)
          factor[p.first][num]++;
      }

      ll ans = 0;
      for (const auto &p : cnt) {
        ll companion = 1;
        bool ok = true;
        for (const auto &q : factor[p.first]) {
          ll need = fexp(q.first, (k - q.second % k) % k);
          if (need > MAXN) {
            ok = false;
            break;
          }
          companion *= need;
          if (companion > MAXN) {
            ok = false;
            break;
          }
        }
        if (ok) {
          for (ll i : coeff) {
            ll val = companion * i;
            if (val > p.first)
              break;
            if (cnt.find(val) != cnt.end()) {
              ll num = (ll)cnt[val] * p.second;
              if (val == p.first)
                num = (ll)cnt[val] * (cnt[val] - 1) / 2;
              ans += num;
            }
          }
        }
      }
      printf("%lld", ans);
      return;
    }

    // k >= 4
    ll ans = 0;
    for (const auto &p : cnt) {
      for (ll i : coeff) {
        if (i % p.first == 0) {
          ll val = i / p.first;
          if (val > p.first)
            break;
          if (cnt.find(val) != cnt.end()) {
            ll num = (ll)cnt[val] * p.second;
            if (val == p.first)
              num = (ll)cnt[val] * (cnt[val] - 1) / 2;
            ans += num;
          }
        }
      }
    }
    printf("%lld", ans);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solution = Solution();
  solution.solve();
}