#include <cstdio>
#include <iostream>
#include <vector>
#define MAXN 200005

using namespace std;

template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-') sig = -1;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

int n, k;
int l[MAXN]{}, r[MAXN]{};
char c[MAXN]{};
bool marked[MAXN]{}, duplicated[MAXN]{};
string s;
vector<int> inorder;

void dfs(int u) {
  if (l[u]) dfs(l[u]);
  inorder.push_back(u);
  if (r[u]) dfs(r[u]);
}

void dfs2(int u, int cost) {
  if (l[u]) {
    dfs2(l[u], cost + 1);
    if (duplicated[l[u]]) {
      duplicated[u] = true;
      cost = 0;
    }
  }

  if (marked[u] && cost <= k) {
    duplicated[u] = true;
    k -= cost;
  }

  if (duplicated[u] && r[u]) dfs2(r[u], 1);
}

int main() {
  read(n), read(k);
  cin >> s;
  for (int i = 1; i <= n; i++) {
    read(l[i]), read(r[i]);
    c[i] = s[i - 1];
  }

  dfs(1);
  char la = '#', lb = '#';
  for (auto it = inorder.rbegin(); it != inorder.rend(); ++it) {
    int u = *it;
    if (c[u] < la || (c[u] == la && c[u] < lb)) marked[u] = true;
    if (c[u] != la) lb = la, la = c[u];
  }

  dfs2(1, 1);

  string ans;
  for (int u : inorder) {
    ans.push_back(c[u]);
    if (duplicated[u]) ans.push_back(c[u]);
  }

  cout << ans << endl;
}