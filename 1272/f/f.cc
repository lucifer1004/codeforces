#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <vector>
#define MAX 205

using namespace std;
int dp[MAX][MAX][MAX], pre[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];

struct State {
  int s, t, open;
  char c;
};

class Solution {
public:
  void solve() {
    string s, t;
    cin >> s >> t;
    int ls = s.size(), lt = t.size();
    memset(dp, INT_MAX, sizeof(dp));
    memset(pre, 0, sizeof(pre));
    memset(visited, false, sizeof(visited));
    dp[0][0][0] = 0;
    pre[0][0][0] = -1;

    vector<State> q;
    int l = 0;
    q.emplace_back(State{0, 0, 0, '#'});
    visited[0][0][0] = true;
    while (l < q.size()) {
      int qs = q[l].s, qt = q[l].t, qo = q[l].open;
      if (qo > 0) {
        int ns = qs, nt = qt, no = qo - 1;
        if (ns < ls && s[ns] == ')') {
          ns++;
        }
        if (nt < lt && t[nt] == ')') {
          nt++;
        }
        dp[ns][nt][no] = dp[qs][qt][qo] + 1;
        if (!visited[ns][nt][no]) {
          visited[ns][nt][no] = true;
          pre[ns][nt][no] = l;
          q.emplace_back(State{ns, nt, no, ')'});
        }
      }

      if (qo < max(ls, lt)) {
        int ns = qs, nt = qt, no = qo + 1;
        if (ns < ls && s[ns] == '(') {
          ns++;
        }
        if (nt < lt && t[nt] == '(') {
          nt++;
        }
        dp[ns][nt][no] = dp[qs][qt][qo] + 1;
        if (!visited[ns][nt][no]) {
          visited[ns][nt][no] = true;
          pre[ns][nt][no] = l;
          q.emplace_back(State{ns, nt, no, '('});
        }
      }

      l++;
    }

    string ans = ")";
    int curr = pre[ls][lt][0];
    while (true) {
      State last = q[curr];
      if (last.c == '#')
        break;
      ans.push_back(last.c);
      curr = pre[last.s][last.t][last.open];
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
  }
};

int main() {
  Solution solution = Solution();
  solution.solve();
}
