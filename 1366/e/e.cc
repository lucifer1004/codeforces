#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;
const ll MOD = 998244353;
void no_answer() {
  printf("0");
  exit(0);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> a(n), b(m);
  map<int, int> first;
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[n - i - 1]);
  for (int i = 0; i < n; ++i)
    if (!first.count(a[i]))
      first[a[i]] = i;
  for (int i = 0; i < m; ++i)
    scanf("%d", &b[m - i - 1]);
  if (n < m)
    no_answer();
  int r = -1;
  ll ans = 1;
  for (int i = 0; i < m; ++i) {
    if (!first.count(b[i]) || first[b[i]] < r)
      no_answer();
    if (i == 0) {
      for (int j = 0; j < first[b[i]]; ++j)
        if (a[j] < b[i])
          no_answer();
      r = first[b[i]];
      continue;
    }
    for (int j = r + 1; j < first[b[i]]; ++j)
      if (a[j] < b[i])
        no_answer();
    int j = r + 1;
    while (a[j] >= b[i - 1])
      j++;
    ans = ans * (j - r) % MOD;
    r = first[b[i]];
  }
  for (int i = n - 1; i >= first[b[m - 1]]; --i)
    if (a[i] < b[m - 1])
      no_answer();
  printf("%lld", ans);
}