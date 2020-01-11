#include <iostream>
#include <unordered_map>

using namespace std;

void solve() {
  int n;
  cin >> n;
  unordered_map<int, int> cnt;
  for (int i = 0; i < n; ++i) {
    int d;
    cin >> d;
    if (d <= 2048) cnt[d]++;
  }

  for (int i = 1; i <= 1024; i <<= 1) {
    cnt[i << 1] += cnt[i] / 2;
  }

  if (cnt[2048])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) solve();
  return 0;
}