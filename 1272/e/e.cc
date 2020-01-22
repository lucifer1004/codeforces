#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 1e8

using namespace std;
typedef long long ll;

class Solution {
public:
  void solve() {
    int n;
    scanf("%d", &n);

    vector<int> a(n + 1), diff(n + 1, INF);
    for (int i = 1; i <= n; ++i)
      scanf("%d", &a[i]);

    vector<vector<int>> to(n + 1);
    vector<int> factor = {-1, 1};
    for (int i = 1; i <= n; ++i) {
      for (int k = 0; k <= 1; ++k) {
        int ni = i + factor[k] * a[i];
        if (ni >= 1 && ni <= n) {
          to[ni].push_back(i);
        }
      }
    }

    for (int p = 0; p <= 1; ++p) {
      vector<bool> visited(n + 1);
      queue<pair<int, int>> q;

      for (int i = 1; i <= n; ++i) {
        if (a[i] % 2 == p) {
          q.push(make_pair(i, 0));
          visited[i] = true;
        }
      }

      while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();
        int ns = front.second + 1;
        for (int i : to[front.first]) {
          if (a[i] % 2 == 1 - p)
            diff[i] = min(diff[i], ns);
          if (!visited[i]) {
            q.push(make_pair(i, ns));
            visited[i] = true;
          }
        }
      }
    }

    for (int i = 1; i <= n; ++i)
      cout << (diff[i] == INF ? -1 : diff[i]) << " ";
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}