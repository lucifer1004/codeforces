#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  bool up = true;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    if (a % 2 == 0)
      cout << a / 2 << endl;
    else {
      if (a > 0)
        cout << (up ? a / 2 + 1 : a / 2) << endl;
      else
        cout << (up ? a / 2 : a / 2 - 1) << endl;
      up = !up;
    }
  }
}