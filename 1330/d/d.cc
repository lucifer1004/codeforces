#include <cstdio>
#include <vector>

using namespace std;
typedef long long ll;

const int maxd = 32;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int d, m;
    scanf("%d%d", &d, &m);
    vector<int> cnt(maxd);
    ll num = 2;
    int i = 1;
    while (num - 1 <= d) {
      cnt[i] = num >> 1;
      num <<= 1;
      i++;
    }
    cnt[i] = d - num / 2 + 1;
    ll ans = 1;
    for (int len = 1; len < maxd; ++len)
      ans = ans * (cnt[len] + 1) % m;
    ans = (ans - 1 + m) % m;
    printf("%lld\n", ans);
  }
}
