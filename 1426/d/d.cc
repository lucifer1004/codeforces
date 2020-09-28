#include <cstdio>
#include <map>

typedef long long ll;

int main() {
  int n;
  scanf("%d", &n);
  std::map<ll, int> last;
  last[0] = 0;
  ll sum = 0;
  int ans = 0, infty = 0;
  for (int i = 1; i <= n; ++i) {
    int a;
    scanf("%d", &a);
    sum += a;
    if (last.count(sum) && last[sum] >= infty) {
      ans++;
      infty = i - 1;
    }
    last[sum] = i;
  }
  printf("%d", ans);
}