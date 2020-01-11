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

class Blockchain {
  vll d;
  int n_;

 public:
  Blockchain(int n) {
    n_ = n;
    d = vll(n + 1);
  }

  void save(int a, int b, ll debt) {
    d[a] -= debt;
    d[b] += debt;
  }

  void solve() {
    vector<Transaction> ans;

    vector<int> positive, negative;
    for (int i = 1; i <= n_; ++i) {
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

    cout << ans.size() << endl;
    for (const auto &t : ans) {
      cout << t.a << " " << t.b << " " << t.debt << endl;
    }
  }
};

void solve() {
  ll n, m;
  cin >> n >> m;

  Blockchain bc = Blockchain(n);
  while (m--) {
    ll a, b, debt;
    cin >> a >> b >> debt;
    bc.save(a, b, debt);
  }

  bc.solve();
}

int main() { solve(); }