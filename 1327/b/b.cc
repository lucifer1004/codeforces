#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<vector<int>> g(n);
    vector<bool> found(n);
    vector<bool> used(n + 1);
    for (int i = 0; i < n; ++i) {
      int k;
      scanf("%d", &k);
      for (int j = 0; j < k; ++j) {
        int m;
        scanf("%d", &m);
        g[i].emplace_back(m);
        if (!found[i] && !used[m]) {
          found[i] = true;
          used[m] = true;
        }
      }
    }
    int last_girl = n - 1;
    while (last_girl >= 0 && found[last_girl])
      last_girl--;
    if (last_girl == -1) {
      printf("OPTIMAL\n");
      continue;
    }
    printf("IMPROVE\n");
    int last_boy = n;
    while (last_boy >= 1 && used[last_boy])
      last_boy--;
    printf("%d %d\n", last_girl + 1, last_boy);
  }
}