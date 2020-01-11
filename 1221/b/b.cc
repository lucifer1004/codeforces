#include <iostream>

using namespace std;

void solve(int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if ((i + j) & 1)
        cout << "B";
      else
        cout << "W";
    }
    cout << endl;
  }
}

int main() {
  int n;
  cin >> n;
  solve(n);
  return 0;
}