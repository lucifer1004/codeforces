#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

struct Transaction {
  int a, b;
  ll debt;
};

class UnionFind {
  vll f, d;
  unordered_map<int, unordered_set<int>> groups;
  int n_;

  int find(int n) {
    if (f[n] == n)
      return n;
    else
      return f[n] = find(f[n]);
  }

 public:
  UnionFind(int n) {
    n_ = n;
    f = vll(n + 1);
    d = vll(n + 1);
    for (int i = 1; i <= n; ++i) f[i] = i;
  }

  void connect(int a, int b, ll debt) {
    int fa = find(a);
    int fb = find(b);
    if (fa != fb) f[fb] = fa;
    d[a] -= debt;
    d[b] += debt;
  }

  void solve() {
    for (int i = 1; i <= n_; ++i) {
      f[i] = find(i);
      groups[f[i]].insert(i);
    }

    vector<Transaction> ans;

    for (const auto &group : groups) {
      vector<int> positive, negative;
      for (const auto &i : group.second) {
        if (d[i] > 0)
          positive.push_back(i);
        else if (d[i] < 0)
          negative.push_back(i);
      }
      int p = 0, n = 0;
      while (p < positive.size() && n < negative.size()) {
        int pp = positive[p];
        int nn = negative[n];
        ll pv = d[pp];
        ll nv = -d[nn];
        if (pv > nv) {
          ans.push_back({nn, pp, nv});
          d[pp] -= nv;
          n++;
        } else if (pv < nv) {
          ans.push_back({nn, pp, pv});
          d[nn] += pv;
          p++;
        } else {
          ans.push_back({nn, pp, pv});
          p++;
          n++;
        }
      }
    }

    cout << ans.size() << endl;
    for (const auto &t : ans) {
      cout << t.a << " " << t.b << " " << t.debt << endl;
    }
  }
};

void solve() {
  ll n, m;
  cin >> n >> m;

  UnionFind uf = UnionFind(n);
  while (m--) {
    ll a, b, debt;
    cin >> a >> b >> debt;
    uf.connect(a, b, debt);
  }

  uf.solve();
}

int main() { solve(); }