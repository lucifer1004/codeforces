#include <iostream>
#include <vector>

using namespace std;
int result;

int query_and(int i, int j) {
  cout << "AND " << i << " " << j << endl;
  cin >> result;
  return result;
}

int query_or(int i, int j) {
  cout << "OR " << i << " " << j << endl;
  cin >> result;
  return result;
}

int query_xor(int i, int j) {
  cout << "XOR " << i << " " << j << endl;
  cin >> result;
  return result;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1), qa(n + 1), x1(n + 1);

  // Query a[i] ^ a[i + 1]
  for (int i = 1; i < n; ++i)
    qa[i] = query_xor(i, i + 1);

  // txor = a[1] ^ a[2] ^ a[3] ^ ... ^ a[n]
  int txor = 0;
  for (int i = 1; i < n; i += 2)
    txor ^= qa[i];

  // Calculate a[1] ^ a[i]
  vector<vector<int>> v(n + 1);
  v[0].emplace_back(1);
  int same = -1;
  for (int i = 2; i <= n; ++i) {
    x1[i] = x1[i - 1] ^ qa[i - 1];
    v[x1[i]].emplace_back(i);
    if (v[x1[i]].size() >= 2)
      same = x1[i];
  }
  if (same != -1) {
    int p = v[same][0], q = v[same][1];
    int det = query_and(p, q);
    a[1] = x1[p] ^ det;
  } else {
    int nei1 = -1;
    for (int i = 2; i <= n; ++i)
      if (x1[i] == 1) {
        nei1 = i;
        break;
      }
    int det1 = query_and(1, nei1);
    int nei2 = -1;
    for (int i = 2; i <= n; ++i)
      if (x1[i] == 2) {
        nei2 = i;
        break;
      }
    int det2 = query_and(1, nei2);
    a[1] = det1 | det2;
  }

  // Restore the rest with a[1]
  for (int i = 2; i <= n; ++i)
    a[i] = x1[i] ^ a[1];

  // Output
  cout << "! ";
  for (int i = 1; i <= n; ++i)
    cout << a[i] << " ";
  cout << endl;
}