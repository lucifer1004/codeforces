#include <iostream>
#include <set>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

class Tree {
  int n_, root_;
  vi parent, c, value, num;
  vvi children;

 public:
  Tree(int n) {
    n_ = n;
    parent = vi(n + 1);
    c = vi(n + 1);
    value = vi(n + 1);
    num = vi(n + 1);
    children = vvi(n + 1);
  }

  void set_root(int i) { root_ = i; }
  void set_parent(int i, int p) {
    parent[i] = p;
    children[p].push_back(i);
  }
  void set_c(int i, int v) { c[i] = v; }

  void dfs(int i) {
    num[i] = 1;
    for (int j : children[i]) {
      dfs(j);
      num[i] += num[j];
    }
  }

  void dfs2(int i, vi &s) {
    value[i] = s[c[i]];
    int current = 0;
    for (int j : children[i]) {
      vi avail;
      for (int k = 0; k < num[j]; ++k) {
        if (current == c[i]) current++;
        avail.push_back(s[current++]);
      }
      dfs2(j, avail);
    }
  }

  void solve() {
    dfs(root_);
    for (int i = 1; i <= n_; ++i)
      if (num[i] <= c[i]) {
        cout << "NO";
        return;
      }

    vi avail;
    for (int i = 1; i <= n_; ++i) avail.push_back(i);
    dfs2(root_, avail);

    cout << "YES" << endl;
    for (int i = 1; i <= n_; ++i) cout << value[i] << " ";
  }
};

void solve() {
  int n;
  cin >> n;
  Tree tree = Tree(n);
  int root;
  for (int i = 1; i <= n; ++i) {
    int p, c;
    cin >> p >> c;
    if (p == 0)
      tree.set_root(i);
    else
      tree.set_parent(i, p);
    tree.set_c(i, c);
  }

  tree.solve();
}

int main() { solve(); }