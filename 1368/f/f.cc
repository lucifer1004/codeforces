#include <iostream>
#include <vector>

using namespace std;
int main() {
  int n;
  cin >> n;
  if (n <= 3) {
    cout << 0 << endl;
    exit(0);
  }
  int best = 0, bestk = 0;
  for (int i = 1; i < n / 2; ++i) {
    int seg = n / (i + 1);
    int rem = n % (i + 1);
    int extra = max(rem - 1, 0);
    int tot = seg * i + extra - i;
    if (tot > best) {
      best = tot;
      bestk = i;
    }
  }
  vector<bool> target(n), on(n);
  for (int i = 0; i < n; ++i) {
    if ((i + 1) % (bestk + 1) != 0 && i != n - 1)
      target[i] = true;
  }
  bool can_light_more = true;
  auto query = [&]() {
    vector<int> op;
    for (int i = 0; i < n; ++i)
      if (target[i] && !on[i]) {
        op.emplace_back(i);
        on[i] = true;
      }
    cout << op.size() << " ";
    for (int i : op)
      cout << i + 1 << " ";
    cout << endl;
    int x;
    cin >> x;
    int inc = op.size();
    for (int i = 0; i < op.size(); ++i) {
      int idx = (x - 1 + i) % n;
      if (on[idx]) {
        on[idx] = false;
        inc--;
      }
    }
    can_light_more = inc > 0;
  };
  while (can_light_more)
    query();
  cout << 0 << endl;
}