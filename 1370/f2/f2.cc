#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

const int N = 1005;
vector<int> a[N];
int depth[N], parent[N];
int n;
map<int, pair<int, int>> memo;

void CLEAR() {
  memo.clear();
  for (int i = 0; i < n; ++i) {
    a[i].clear();
    depth[i] = 0;
    parent[i] = -1;
  }
}

void DFS(int u, int p) {
  parent[u] = p;
  depth[u] = p < 0 ? 0 : depth[p] + 1;
  for (auto &v : a[u]) {
    if (v != p)
      DFS(v, u);
  }
}

void QUERY(int &node, int &dist, vector<int> &nodes) {
  cout << "? " << nodes.size() << " ";
  for (int u : nodes)
    cout << u + 1 << " ";
  cout << endl;
  cin >> node >> dist;
  if (dist == -1)
    exit(0);
  node--;
}

void QUERY(int layer, int &node, int &dist) {
  if (memo.count(layer)) {
    node = memo[layer].first;
    dist = memo[layer].second;
    return;
  }
  vector<int> nodes;
  for (int i = 0; i < n; ++i)
    if (depth[i] == layer)
      nodes.emplace_back(i);
  QUERY(node, dist, nodes);
  memo[layer] = {node, dist};
}

void OUTPUT(int u, int v) {
  cout << "! " << u + 1 << " " << v + 1 << endl;
  string result;
  cin >> result;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    CLEAR();
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      a[u].emplace_back(v);
      a[v].emplace_back(u);
    }
    vector<int> nodes;
    for (int i = 0; i < n; ++i)
      nodes.emplace_back(i);
    int node, min_dist;
    QUERY(node, min_dist, nodes);
    DFS(node, -1);
    int max_depth = 0;
    for (int i = 0; i < n; ++i)
      max_depth = max(max_depth, depth[i]);
    int lo = (min_dist + 1) / 2, hi = min(max_depth, min_dist);
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      int _node, _dist;
      QUERY(mid, _node, _dist);
      if (_dist > min_dist)
        hi = mid - 1;
      else
        lo = mid + 1;
    }
    int u, v;
    QUERY(hi, u, min_dist);
    int current = u;
    while (current != node) {
      depth[current] = N;
      current = parent[current];
    }
    int dv = min_dist - hi;
    nodes.clear();
    for (int i = 0; i < n; ++i)
      if (depth[i] == dv)
        nodes.emplace_back(i);
    QUERY(v, min_dist, nodes);
    OUTPUT(u, v);
  }
}