#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
ifstream fin;

class Solution {
public:
  void solve() {
    int n;
    vector<int> p(12);
    for (int i = 0; i < 12; ++i)
      fin >> p[i];
    bool good = true;
    if (p[0] > p[1] || p[1] > p[2] || p[2] > p[3])
      good = false;
    int lo = 100;
    for (int i = 4; i < 12; ++i)
      lo = min(lo, p[i]);
    if (lo < p[3])
      good = false;
    cout << (good ? "yes" : "no") << endl;
  }
};

int main() {
  fin = ifstream("hello.in");
  int t;
  fin >> t;
  while (t--) {
    Solution solution = Solution();
    solution.solve();
  }
}