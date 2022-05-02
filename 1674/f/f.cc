#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-') sig = -1;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

template <class T>
class FenwickTree {
  int limit;
  vector<T> arr;

  int lowbit(int x) { return x & (-x); }

 public:
  FenwickTree(int limit) {
    this->limit = limit;
    arr = vector<T>(limit + 1);
  }

  void update(int idx, T delta) {
    for (; idx <= limit; idx += lowbit(idx)) arr[idx] += delta;
  }

  T query(int idx) {
    T ans = 0;
    for (; idx > 0; idx -= lowbit(idx)) ans += arr[idx];
    return ans;
  }
};

int main() {
  int n, m, q;
  read(n), read(m), read(q);
  FenwickTree<int> ft(n * m);
  vector<int> v(n * m + 1);

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) {
      if (s[j] == '*') {
        int id = j * n + i + 1;
        ft.update(id, 1);
        v[id] = 1;
        cnt++;
      }
    }
  }

  while (q--) {
    int x, y;
    read(x), read(y);
    int id = (y - 1) * n + x;
    if (v[id]) {
      ft.update(id, -1);
      v[id] = 0;
      cnt--;
    } else {
      ft.update(id, 1);
      v[id] = 1;
      cnt++;
    }

    cout << cnt - ft.query(cnt) << endl;
  }
}