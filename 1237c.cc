#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
  int x, y, z, id;
};

int main() {
  int n;
  cin >> n;
  vector<Point> p(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
    p[i].id = i + 1;
  }
  sort(p.begin(), p.end(), [](Point &a, Point &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y) ||
           (a.x == b.x && a.y == b.y && a.z < b.z);
  });
  vector<bool> used(n);
  for (int i = 0; i < n - 1; ++i) {
    if (p[i].x == p[i + 1].x && p[i].y == p[i + 1].y) {
      cout << p[i].id << " " << p[i + 1].id << endl;
      used[i] = true;
      used[i + 1] = true;
      i++;
    }
  }
  vector<Point> q;
  for (int i = 0; i < n; ++i)
    if (!used[i])
      q.emplace_back(p[i]);
  int m = q.size();
  if (m == 0)
    return 0;
  used = vector<bool>(m);
  for (int i = 0; i < m - 1; ++i) {
    if (q[i].x == q[i + 1].x) {
      cout << q[i].id << " " << q[i + 1].id << endl;
      used[i] = true;
      used[i + 1] = true;
      i++;
    }
  }
  p.clear();
  for (int i = 0; i < m; ++i)
    if (!used[i])
      p.emplace_back(q[i]);
  int t = p.size();
  for (int i = 0; i < t; i += 2)
    cout << p[i].id << " " << p[i + 1].id << endl;
}