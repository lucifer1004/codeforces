#include <algorithm>
#include <iostream>

using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.size();
  cout << 3 << endl;
  cout << "L 2" << endl;
  cout << "R 2" << endl;
  cout << "R " << 2 * n - 1 << endl;
}