#include <iostream>
#include <vector>

using namespace std;

class Solution {
  int n, m, k;
  vector<int> times;
  vector<string> commands;
  void output() {
    cout << commands.size() << endl;
    for (int i = 0; i < times.size(); ++i)
      cout << times[i] << " " << commands[i] << endl;
  }

  void execute(string command, int time) {
    commands.emplace_back(command);
    times.emplace_back(time);
    k -= command.size() * time;
    if (k == 0) {
      output();
      exit(0);
    }
  }

public:
  void solve() {
    scanf("%d%d%d", &n, &m, &k);
    int limit = 4 * n * m - 2 * n - 2 * m;
    if (limit < k) {
      cout << "NO" << endl;
      return;
    }
    cout << "YES" << endl;

    if (n == 1) {
      execute("R", min(k, m - 1));
      execute("L", k);
    }

    if (m == 1) {
      execute("D", min(k, n - 1));
      execute("U", k);
    }

    bool back = false;
    int row = 1;
    while (k > 0) {
      if (!back) {
        execute("R", min(k, m - 1));
        if (row < n) {
          int step = min(k, 3 * (m - 1));
          int first = step / 3;
          if (first > 0)
            execute("DLU", first);
          if (step % 3 != 0)
            execute(string("DLU").substr(0, step % 3), 1);
          execute("D", 1);
          if (++row == n)
            back = true;
        }
      } else {
        execute("R", min(k, m - 1));
        execute("U", min(k, n - 1));
        execute("L", min(k, m - 1));
      }
    }
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}