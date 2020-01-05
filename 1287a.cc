#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  string state;
  cin >> state;

  int time = 0;
  while (true) {
    bool changed = false;
    string new_state(state);
    for (int i = 0; i < n - 1; ++i) {
      if (state[i] == 'A' && state[i + 1] == 'P') {
        new_state[i + 1] = 'A';
        changed = true;
      }
    }
    if (changed) {
      time++;
      state = new_state;
    } else
      break;
  }
  cout << time << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}