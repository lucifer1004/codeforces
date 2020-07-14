#include <cstdio>
#include <iostream>
#include <vector>

#define lson(idx) ((idx) << 1)
#define rson(idx) ((idx) << 1 | 1)
#define MAXN 200005

template <typename T> void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-')
      sig = -1;
  for (; isdigit(c); c = getchar())
    x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

using namespace std;
int r, n, m;

struct Matrix {
  int a[2][2]{};

  Matrix() {}

  Matrix operator*(Matrix other) {
    Matrix ans;
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k)
          ans.a[i][j] += a[i][k] * other.a[k][j];
        ans.a[i][j] %= r;
      }

    return ans;
  }
} s[MAXN * 4];

vector<Matrix> a;

void calc(int idx) {
  int l = lson(idx);
  int r = rson(idx);
  s[idx] = s[l] * s[r];
}

void build(int idx, int l, int r) {
  if (l == r)
    s[idx] = a[l - 1];
  else {
    int mid = (l + r) >> 1;
    build(lson(idx), l, mid);
    build(rson(idx), mid + 1, r);
    calc(idx);
  }
}

Matrix query(int idx, int l, int r, int cl, int cr) {
  if (cl >= l && cr <= r)
    return s[idx];
  int mid = (cl + cr) >> 1;
  Matrix ans;
  for (int i = 0; i < 2; ++i)
    ans.a[i][i] = 1;
  if (l <= mid)
    ans = ans * query(lson(idx), l, r, cl, mid);
  if (mid < r)
    ans = ans * query(rson(idx), l, r, mid + 1, cr);
  return ans;
}

int main() {
  read(r), read(n), read(m);
  for (int i = 0; i < n; ++i) {
    Matrix mat;
    for (int j = 0; j < 2; ++j)
      for (int k = 0; k < 2; ++k) {
        int v;
        read(v);
        v %= r;
        mat.a[j][k] = v;
      }
    a.push_back(mat);
  }
  build(1, 1, n);
  string output;
  for (int i = 0; i < m; ++i) {
    int l, r;
    read(l), read(r);
    Matrix ans = query(1, l, r, 1, n);
    for (auto &j : ans.a) {
      for (int k : j)
        output += to_string(k) + " ";
      output += "\n";
    }
    output += "\n";
  }
  printf("%s", output.c_str());
}