#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int check(string s) {
  int l = 0, p = 0, ur = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '(')
      l++;
    else {
      if (l > 0) {
        l--;
        if (l == 0)
          p++;
      } else {
        ur++;
        p = 0;
      }
    }
  }
  if (ur > 0)
    p++;
  return p;
}

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int l = 0;
  for (int i = 0; i < n; ++i)
    l += s[i] == '(';
  if (l != n - l) {
    cout << 0 << endl;
    cout << 1 << " " << 1 << endl;
    return 0;
  }

  int ans = check(s), li = 1, ri = 1;
  for (int i = 0; i < n - 1; ++i)
    for (int j = i + 1; j < n; ++j) {
      string t = s;
      if (s[i] != s[j])
        swap(t[i], t[j]);
      int res = check(t);
      if (res > ans) {
        ans = res;
        li = i + 1;
        ri = j + 1;
      }
    }

  cout << ans << endl;
  cout << li << " " << ri << endl;
}