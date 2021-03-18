#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool prime[5000];
vector<int> primes;

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
    vector<int> a(n), pre(n, -1);
    map<int, int> pos;
    for (int i = 0; i < n; ++i) {
      read(a[i]);
      for (int prime : primes) {
        if (prime > a[i]) break;
        while (a[i] % (prime * prime) == 0) a[i] /= prime * prime;
      }
      if (pos.count(a[i])) pre[i] = pos[a[i]];
      pos[a[i]] = i;
    }
    vector<pair<int, int>> best(k + 1, {1, 0});
    vector<pair<int, int>> second_best(k + 1, {1, 0});
    for (int i = 1; i < n; ++i) {
      for (int j = k; j >= 0; --j) {
        if (j < k) {
          if (best[j] < best[j + 1]) {
            second_best[j + 1] = best[j + 1];
            best[j + 1] = best[j];
          } else if (best[j] < second_best[j + 1])
            second_best[j + 1] = best[j];
        }
        if (pre[i] >= -best[j].second) {
          best[j] = {best[j].first + 1, -i};
        }
        if (pre[i] >= -second_best[j].second) {
          second_best[j] = {second_best[j].first + 1, -i};
        }
        if (second_best[j] < best[j]) swap(second_best[j], best[j]);
      }
    }
    printf("%d\n", min_element(best.begin(), best.end())->first);
  }
};

void init() {
  for (int i = 2; i < 5000; ++i) prime[i] = true;
  primes.clear();
  primes.reserve(5000);
  for (int i = 2; i < 5000; ++i) {
    if (prime[i]) {
      primes.emplace_back(i);
      for (int j = i * 2; j < 5000; j += i) prime[j] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  init();

  int t;
  read(t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}