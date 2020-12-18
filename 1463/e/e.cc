#include <iostream>
#include <queue>
#include <set>
#include <vector>
#define MAXN 300005

using namespace std;

int n, k;
int p[MAXN]{}, nxt[MAXN]{}, pre[MAXN]{}, anc[MAXN]{}, depth[MAXN]{};
vector<int> out[MAXN]{};

int find(int x) { return anc[x] == x ? x : (anc[x] = find(anc[x])); }

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i)
    cin >> p[i], anc[i] = i;

  // Align neighbors and validate (multiple branches or loops are not allowed).
  // Use path compression to find the head of each neighborhood chain
  // efficiently.
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    if (nxt[x] || pre[y] || find(x) == find(y)) {
      cout << 0 << endl;
      return 0;
    }
    nxt[x] = y;
    pre[y] = x;
    anc[y] = find(x);
  }

  // Calculate depth of each element in a neighborhood chain.
  for (int i = 1; i <= n; ++i) {
    if (find(i) == i) {
      int u = i;
      int d = 0;
      while (u) {
        depth[u] = d++;
        u = nxt[u];
      }
    }
  }

  // Build the chain graph (each node represents a neighborhood chain).
  // If both nodes belong to the same chain, validate their depth.
  vector<int> in_degree(n + 1);
  for (int i = 1; i <= n; ++i) {
    int req = p[i];
    if (req != 0) {
      int u = find(req), v = find(i);
      if (u == v) {
        if (depth[req] > depth[i]) {
          cout << 0 << endl;
          return 0;
        }
        continue;
      }
      out[u].emplace_back(v);
      in_degree[v]++;
    }
  }

  // Do a topological sort to get the final order.
  queue<int> q;
  for (int i = 1; i <= n; ++i)
    if (find(i) == i && in_degree[i] == 0)
      q.emplace(i);

  vector<int> ans;
  ans.reserve(n);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : out[u]) {
      if (--in_degree[v] == 0)
        q.emplace(v);
    }
    while (u != 0) {
      ans.emplace_back(u);
      u = nxt[u];
    }
  }

  if (ans.size() == n) {
    for (int i : ans)
      cout << i << " ";
    cout << endl;
  } else
    cout << 0 << endl;
}