#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> qa, qb;

void query(int x) {
  cout << "+ " << x << endl;
  int a, b;
  cin >> a >> b;
  qa.emplace_back(a), qb.emplace_back(b);
}

class Solution {
public:
  void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> ans(n + 1), curr(n + 1);
    map<int, int> dict;
    for (int i = 1; i < n * n; ++i)
      dict[i * (i - 1) / 2] = i;
    for (int i = 1; i < n; ++i)
      query(i);
    query(1);
    for (int i = 2; i < n; ++i) {
      int da = qa[i - 1] - qa[i - 2];
      if (da != 0) {
        ans[i] = dict[da];
        curr[i] = ans[i] + 1;
      }
    }
    int da = qa[n - 1] - qa[n - 2];
    ans[1] = dict[da] - 1;
    curr[1] = ans[1] + 1;
    int db = qb[n - 1] - qb[n - 2];
    if (ans[2] == 0 && ans[3] == 0) {
      if (db == 1) {
        curr[2] = 1;
        curr[3] = 1;
      }
      if (db == 4) {
        ans[2] = 1;
        ans[3] = 1;
        curr[2] = 2;
        curr[3] = 2;
      }
      if (db == 2) {
        int delta = qb[1] - qb[0];
        if (delta == 0) {
          ans[2] = 1;
          curr[2] = 2;
          curr[3] = 1;
        } else {
          ans[3] = 1;
          curr[3] = 2;
          curr[2] = 1;
        }
      }
    }
    if (curr[2] == 0) {
      ans[2] = db / curr[3] - 1;
      curr[2] = ans[2] + 1;
    }
    if (curr[3] == 0) {
      ans[3] = db / curr[2] - 1;
      curr[3] = ans[3] + 1;
    }

    for (int i = 3; i < n - 1; ++i) {
      if (ans[i + 1] != 0)
        continue;
      int db = qb[i - 1] - qb[i - 2];
      db -= curr[i - 1] * curr[i - 2];
      if (db == 0)
        curr[i + 1] = 1;
      else {
        ans[i + 1] = 1;
        curr[i + 1] = 2;
      }
    }

    db = qb[n - 2] - qb[n - 3];
    ans[n] = db / curr[n - 2] - curr[n - 3];

    cout << "! ";
    for (int i = 1; i <= n; ++i)
      cout << ans[i] << " ";
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}