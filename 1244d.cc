#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

class Graph {
  vector<int> in;
  vector<vector<int>> adj;
  int head, maxin;

public:
  Graph(int n) {
    in = vector<int>(n);
    adj = vector<vector<int>>(n);
    maxin = 0;
  }

  void add_edge(int a, int b) {
    in[a]++;
    in[b]++;
    maxin = max(maxin, max(in[a], in[b]));
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
  }

  bool is_valid() { return maxin <= 2; }

  vector<int> sort() {
    int i = 0;
    while (in[i] > 1)
      i++;
    head = i;
    vector<int> seq;
    seq.emplace_back(head);
    while (seq.size() < in.size()) {
      int j = 0;
      while (adj[i][j] == head)
        j++;
      head = i;
      i = adj[head][j];
      seq.emplace_back(i);
    }
    return seq;
  }
};

int main() {
  int n;
  cin >> n;
  vector<vector<int>> c(3, vector<int>(n));
  for (int i = 0; i < n; ++i)
    scanf("%d", &c[0][i]);
  for (int i = 0; i < n; ++i)
    scanf("%d", &c[1][i]);
  for (int i = 0; i < n; ++i)
    scanf("%d", &c[2][i]);
  Graph g(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    g.add_edge(a - 1, b - 1);
  }
  if (!g.is_valid())
    cout << -1;
  else {
    vector<int> seq = g.sort();
    ll fab = 0, fac = 0, fba = 0, fbc = 0, fca = 0, fcb = 0;
    for (int i = 0; i < n; ++i) {
      int j = seq[i];
      if (i % 3 == 0) {
        fab += c[0][j];
        fac += c[0][j];
        fba += c[1][j];
        fbc += c[1][j];
        fca += c[2][j];
        fcb += c[2][j];
      } else if (i % 3 == 1) {
        fab += c[1][j];
        fac += c[2][j];
        fba += c[0][j];
        fbc += c[2][j];
        fca += c[0][j];
        fcb += c[1][j];
      } else {
        fab += c[2][j];
        fac += c[1][j];
        fba += c[2][j];
        fbc += c[0][j];
        fca += c[1][j];
        fcb += c[0][j];
      }
    }
    ll ma = min(fab, fac);
    ll mb = min(fba, fbc);
    ll mc = min(fca, fcb);
    ll ans = min(ma, min(mb, mc));
    cout << ans << endl;
    vector<int> color(n);
    if (ans == fab) {
      for (int i = 0; i < n; ++i) {
        int j = seq[i];
        if (i % 3 == 0)
          color[j] = 1;
        else if (i % 3 == 1)
          color[j] = 2;
        else
          color[j] = 3;
      }
    } else if (ans == fac) {
      for (int i = 0; i < n; ++i) {
        int j = seq[i];
        if (i % 3 == 0)
          color[j] = 1;
        else if (i % 3 == 1)
          color[j] = 3;
        else
          color[j] = 2;
      }
    } else if (ans == fba) {
      for (int i = 0; i < n; ++i) {
        int j = seq[i];
        if (i % 3 == 0)
          color[j] = 2;
        else if (i % 3 == 1)
          color[j] = 1;
        else
          color[j] = 3;
      }
    } else if (ans == fbc) {
      for (int i = 0; i < n; ++i) {
        int j = seq[i];
        if (i % 3 == 0)
          color[j] = 2;
        else if (i % 3 == 1)
          color[j] = 3;
        else
          color[j] = 1;
      }
    } else if (ans == fca) {
      for (int i = 0; i < n; ++i) {
        int j = seq[i];
        if (i % 3 == 0)
          color[j] = 3;
        else if (i % 3 == 1)
          color[j] = 1;
        else
          color[j] = 2;
      }
    } else {
      for (int i = 0; i < n; ++i) {
        int j = seq[i];
        if (i % 3 == 0)
          color[j] = 3;
        else if (i % 3 == 1)
          color[j] = 2;
        else
          color[j] = 1;
      }
    }
    for (int i = 0; i < n; ++i)
      cout << color[i] << " ";
  }
}