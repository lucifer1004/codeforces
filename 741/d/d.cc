#include <cstring>
#include <iostream>
#include <vector>
#define MAXN 500005

using namespace std;
struct Edge {
  int to, color;
};
vector<Edge> adj[MAXN];
int mask[MAXN], num[MAXN];
void dfs(int u) {
  num[u] = 1;
  for (Edge e : adj[u]) {
    mask[e.to] = mask[u] ^ (1 << e.color);
    dfs(e.to);
    num[u] += num[e.to];
  }
}
int main() {
  int n;
  cin >> n;
  memset(mask, 0, sizeof(mask));
  memset(num, 0, sizeof(num));
  for (int i = 0; i < n - 1; ++i) {
    int p;
    char c;
    cin >> p >> c;
    adj[p - 1].push_back(Edge{i + 1, c - 'a'});
  }
  dfs(0);
}