#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> match(string &s, string &t) {
  int ls = s.size(), lt = t.size();
  vector<int> ans(lt + 1);
  int i = 0, j = 0;
  while (j < lt) {
    while (s[i] != t[j])
      i++;
    ans[j + 1] = i + 1;
    i++;
    j++;
  }
  return ans;
}

int main() {
  string s, t;
  cin >> s >> t;
  vector<int> forward = match(s, t);
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  vector<int> backward = match(s, t);
  int ls = s.size(), lt = t.size();
  int ans = 0;
  for (int i = 0; i <= lt; ++i)
    ans = max(ans, ls - forward[i] - backward[lt - i]);
  cout << ans;
}