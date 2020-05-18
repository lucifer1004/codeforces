#include <iostream>
#include <queue>
#include <vector>

struct Segment {
  int len, left;
  bool operator<(const Segment &that) const {
    return len < that.len || (len == that.len && left > that.left);
  }
};

using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    priority_queue<Segment> pq;
    pq.push(Segment{n, 0});
    vector<int> ans(n);
    int idx = 1;
    while (!pq.empty()) {
      Segment f = pq.top();
      pq.pop();
      int mid = f.left + (f.len - 1) / 2;
      int right = f.left + f.len - 1;
      ans[mid] = idx++;
      if (mid > f.left)
        pq.push(Segment{mid - f.left, f.left});
      if (mid < right)
        pq.push(Segment{right - mid, mid + 1});
    }
    for (int i : ans)
      cout << i << " ";
    cout << endl;
  }
}