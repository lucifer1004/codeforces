#include <iostream>
#include <vector>

using namespace std;

struct Segment {
  int l, r;
};

int main() {
  int n;
  cin >> n;
  vector<Segment> segments;
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    segments.emplace_back(Segment{l, r});
  }
  vector<vector<int>> adj(n);
  vector<int> degree(n);
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) {
      int l = max(segments[i].l, segments[j].l);
      int r = min(segments[i].r, segments[j].r);
      if (l < r) {
        adj[i].emplace_back(j);
        adj[j].emplace_back(i);
      }
    }
  int maxd = 0;
  int idx = -1;
  for (int i = 0; i < n; ++i) {
    degree[i] = adj[i].size();
    if (degree[i] > maxd) {
      maxd = degree[i];
      idx = i;
    }
  }
  if (maxd == 0) {
    cout << n << endl;
    for (int i = 1; i <= n; ++i)
      cout << i << " ";
  } else {
    for (int v : adj[idx])
      degree[v]--;
    for (int i = 0; i < n; ++i)
      if (i != idx && degree[i] > 0) {
        cout << 0;
        return 0;
      }
    if (maxd == 1) {
      cout << 2 << endl;
      cout << idx + 1 << " " << adj[idx][0] + 1;
    } else {
      cout << 1 << endl;
      cout << idx + 1;
    }
  }
}