#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> primes = {2, 3, 5, 7, 11, 13};
  for (int k = 8; k * 2 + 1 <= n; ++k) {
    int t = k * 2 + 1;
    bool is_prime = true;
    for (int j = 0; primes[j] * primes[j] <= t; ++j) {
      if (t % primes[j] == 0) {
        is_prime = false;
        break;
      }
    }
    if (is_prime)
      primes.emplace_back(t);
  }
  while (!primes.empty() && primes.back() > n)
    primes.pop_back();
  int cnt = primes.size() + 1;
  vector<int> ans(n + 1);
  for (int i = 2; i <= cnt; ++i)
    ans[i] = 1;
  vector<bool> used(n + 1);
  for (int prime : primes)
    used[prime] = true;
  used[1] = true;
  vector<vector<int>> second(n + 1);
  for (int i = 1; i <= n; ++i) {
    if (used[i])
      continue;
    for (int j = 0; primes[j] * primes[j] <= i; ++j) {
      if (i % primes[j] == 0) {
        second[i / primes[j]].emplace_back(i);
        break;
      }
    }
  }
  for (int i = 2; i <= n / 2; ++i) {
    for (int k : second[i]) {
      if (!used[k]) {
        used[k] = true;
        ans[++cnt] = i;
      }
    }
  }
  for (int i = 2; i <= n; ++i)
    cout << ans[i] << " ";
}