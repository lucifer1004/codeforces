#include <iostream>
#include <set>
#include <vector>

using namespace std;
int query(int n) {
  cout << "? " << n << " ";
  for (int i = 1; i <= n; ++i)
    cout << i << " ";
  cout << endl;
  int result;
  cin >> result;
  return result;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<set<int>> s(k);
    for (int i = 0; i < k; ++i) {
      int c;
      cin >> c;
      for (int j = 0; j < c; ++j) {
        int si;
        cin >> si;
        s[i].insert(si);
      }
    }
    int mx = query(n);
    int l = 1, r = n - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      int val = query(mid);
      if (val == mx)
        r = mid - 1;
      else
        l = mid + 1;
    }
    int idx = l;
    vector<int> ans(k);
    for (int i = 0; i < k; ++i) {
      if (s[i].count(idx)) {
        cout << "? " << n - (int)s[i].size() << " ";
        for (int j = 1; j <= n; ++j)
          if (!s[i].count(j))
            cout << j << " ";
        cout << endl;
        int result;
        cin >> result;
        ans[i] = result;
      } else {
        ans[i] = mx;
      }
    }
    cout << "! ";
    for (int i : ans)
      cout << i << " ";
    cout << endl;
    string ok;
    cin >> ok;
  }
}