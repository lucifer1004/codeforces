#include <iostream>

using namespace std;

int main() {
  int k;
  cin >> k;
  int a = (1 << 18) - 1;
  int p = a - k;
  cout << "2 3" << endl;
  cout << a << " " << k << " " << p << endl;
  cout << p << " " << a << " " << k << endl;
}