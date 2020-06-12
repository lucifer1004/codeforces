#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll fexp(ll x, ll y) {
  ll ans = 1;
  while (y) {
    if (y & 1)
      ans = ans * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  string ans;
  while (t--) {
    int n, p;
    scanf("%d%d", &n, &p);
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
      int k;
      scanf("%d", &k);
      cnt[k]++;
    }
    if (p == 1)
      ans += to_string(n % 2) + "\n";
    else {
      ll delta = 0;
      map<int, bool> extra;
      for (auto it = cnt.begin(); it != cnt.end(); ++it) {
        int i = it->first, num = it->second;
        if (num >= p) {
          cnt[i + 1] += num / p;
          extra[i + 1] = true;
          it->second %= p;
        }
      }
      bool det = false;
      for (auto it = cnt.rbegin(); it != cnt.rend(); ++it) {
        if (!det) {
          if (it->second % 2 == 0)
            continue;
          else if (extra[it->first] && cnt.count(it->first - 1))
            cnt[it->first - 1] += p;
          else {
            delta = fexp(p, it->first);
            det = true;
          }
        } else {
          delta -= fexp(p, it->first) * it->second;
          delta = (delta % MOD + MOD) % MOD;
        }
      }
      ans += to_string(delta) + "\n";
    }
  }
  printf("%s", ans.c_str());
}