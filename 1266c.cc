#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

void solve() {
  int r, c;
  cin >> r >> c;
  if (r == 1 && c == 1)
    cout << 0 << endl;
  else if (r == 1) {
    for (int i = 0; i < c; ++i) cout << i + 2 << " ";
    cout << endl;
  } else if (c == 1) {
    for (int i = 0; i < r; ++i) cout << i + 2 << endl;
  } else {
    vll first(c);
    for (int i = 0; i < c; ++i) {
      first[i] = i + 2;
      cout << first[i] << " ";
    }
    cout << endl;
    for (int i = 1; i < r; ++i) {
      for (int j = 0; j < c; ++j) cout << first[j] * (c + 1 + i) << " ";
      cout << endl;
    }
  }
}

int main() { solve(); }