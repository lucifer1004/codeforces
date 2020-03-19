#include <cstring>
#include <iostream>

int a[500005];
int b[751][751];

int main() {
  std::memset(a, 0, sizeof(a));
  std::memset(b, 0, sizeof(b));
  int q;
  std::cin >> q;
  for (int i = 0; i < q; ++i) {
    int t, x, y;
    std::cin >> t >> x >> y;
    if (t == 1) {
      a[x] += y;
      for (int j = 1; j <= 750; ++j)
        b[j][x % j] += y;
    } else {
      if (x <= 750)
        std::cout << b[x][y] << std::endl;
      else {
        int ans = 0;
        for (int j = y; j <= 500000; j += x)
          ans += a[j];
        std::cout << ans << std::endl;
      }
    }
  }
}