#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int count = 0, idx = -1, fail = 0;
  int children[26]{};
};

class AhoCorasickAutomaton {
  vector<Node> nodes;
  vector<string> dict;
  vector<int> mapping;

public:
  explicit AhoCorasickAutomaton() {
    nodes = vector<Node>(1);
    dict = vector<string>();
    mapping = vector<int>();
  }

  void add_word(string &word) {
    dict.emplace_back(word);
    int curr = 0;
    for (const char &c : word) {
      if (!nodes[curr].children[c - 'a']) {
        nodes[curr].children[c - 'a'] = nodes.size();
        nodes.emplace_back(Node());
      }
      curr = nodes[curr].children[c - 'a'];
    }
    if (nodes[curr].idx == -1) {
      nodes[curr].idx = (int)dict.size() - 1;
      mapping.emplace_back(dict.size() - 1);
    } else
      mapping.emplace_back(nodes[curr].idx);
  }

  void build() {
    queue<int> q;
    for (int u : nodes[0].children)
      if (u)
        q.push(u);

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int i = 0; i < 26; ++i) {
        auto &v = nodes[u].children[i];
        if (v) {
          nodes[v].fail = nodes[nodes[u].fail].children[i];
          q.push(v);
        } else
          v = nodes[nodes[u].fail].children[i];
      }
    }
  }

  vector<int> process(string &s) {
    int n = s.size();
    vector<int> ans(dict.size());
    int curr = 0;
    int idx = 0;
    while (idx < n) {
      char c = s[idx];
      if (nodes[curr].children[c - 'a']) {
        curr = nodes[curr].children[c - 'a'];
        nodes[curr].count++;
        idx++;
      } else {
        curr = nodes[curr].fail;
        if (!curr)
          idx++;
      }
    }

    // Topological sort
    int N = nodes.size();
    vector<int> out(N);
    for (int i = 0; i < N; ++i)
      out[nodes[i].fail]++;
    queue<int> q;
    for (int i = 0; i < N; ++i)
      if (!out[i])
        q.push(i);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (nodes[u].idx != -1)
        ans[nodes[u].idx] += nodes[u].count;
      nodes[nodes[u].fail].count += nodes[u].count;
      out[nodes[u].fail]--;
      if (!out[nodes[u].fail])
        q.push(nodes[u].fail);
    }

    for (int i = 0; i < dict.size(); ++i)
      ans[i] = ans[mapping[i]];
    return ans;
  }
};

int main() {
  int n;
  cin >> n;
  AhoCorasickAutomaton aca;
  for (int i = 0; i < n; ++i) {
    string t;
    cin >> t;
    aca.add_word(t);
  }
  aca.build();
  string s;
  cin >> s;
  vector<int> ans = aca.process(s);
  for (int i : ans)
    cout << i << endl;
}