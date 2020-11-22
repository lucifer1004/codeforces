#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

template <typename T> void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-')
      sig = -1;
  for (; isdigit(c); c = getchar())
    x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

class Solution {
public:
  void solve() {
    int n, k;
    read(n), read(k);
    string a, b;
    cin >> a >> b;
    vector<int> ca(26), cb(26);
    for (char c : a)
      ca[c - 'a']++;
    for (char c : b)
      cb[c - 'a']++;
    for (int i = 0; i < 26; ++i) {
      if (ca[i] < cb[i]) {
        cout << "No" << endl;
        return;
      }
      ca[i] -= cb[i];
      if (i < 25)
        ca[i + 1] += ca[i] / k * k;
    }
    cout << "Yes" << endl;
  }
};

int main() {
  int t;
  read(t);
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}