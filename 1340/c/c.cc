#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, m, g, r;

struct Node {
  int sec, red, curr;
  bool operator<(const Node a) const {
    return sec + red * r < a.sec + a.red * r;
  }
  bool operator>(const Node a) const {
    return sec + red * r > a.sec + a.red * r;
  }
};

int main() {
  cin >> n >> m;
  vector<int> d(m);
  for (int i = 0; i < m; ++i)
    cin >> d[i];
  sort(d.begin(), d.end());
  cin >> g >> r;
  vector<vector<bool>> vis(m, vector<bool>(g + 1));
  priority_queue<Node, vector<Node>, greater<>> q;
  q.push({0, 0, 0});
  vis[0][0] = true;
  while (!q.empty()) {
    auto [sec, red, curr] = q.top();
    q.pop();
    if (curr == m - 1) {
      cout << sec + red * r;
      return 0;
    }
    if (curr > 0) {
      int dist = d[curr] - d[curr - 1];
      int nxt = sec + dist;
      if (dist <= g - sec % g && !vis[curr - 1][nxt % g]) {
        vis[curr - 1][nxt % g] = true;
        q.push(Node{nxt, red + (nxt % g == 0), curr - 1});
      }
    }
    if (curr < m) {
      int dist = d[curr + 1] - d[curr];
      int nxt = sec + dist;
      if (dist <= g - sec % g && !vis[curr + 1][nxt % g]) {
        vis[curr + 1][nxt % g] = true;
        q.push(Node{nxt, red + (nxt % g == 0 && curr + 1 != m - 1), curr + 1});
      }
    }
  }
  cout << -1;
}