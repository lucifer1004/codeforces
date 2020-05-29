#include <iostream>
#include <set>
#include <vector>

using namespace std;
int n, m;
vector<string> a;
string ans;
vector<set<char>> possible;
vector<int> diff;
bool found;

int distance(string a, string b) {
  int cnt = 0;
  for (int i = 0; i < a.size(); ++i)
    if (a[i] != b[i])
      cnt++;
  return cnt;
}

void dfs() {
  int t = ans.size();
  if (t == m) {
    found = true;
    return;
  }
  for (char c : possible[t]) {
    bool ok = true;
    for (int i = 0; i < n; ++i)
      if (diff[i] + (c != a[i][t]) > 1) {
        ok = false;
        break;
      }
    if (ok) {
      ans.push_back(c);
      for (int i = 0; i < n; ++i)
        diff[i] += c != a[i][t];
      dfs();
      if (found)
        return;
      ans.pop_back();
      for (int i = 0; i < n; ++i)
        diff[i] -= c != a[i][t];
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    a = vector<string>(n, "");
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    bool ok = true;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        if (distance(a[i], a[j]) > 2)
          ok = false;
    if (!ok) {
      cout << -1 << endl;
      continue;
    }
    ans = "";
    found = false;
    possible = vector<set<char>>(m);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        possible[j].insert(a[i][j]);
    diff = vector<int>(n);
    dfs();
    if (!found)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
}