#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;
typedef unsigned long long ll;

struct Person {
  ll skill, point, count;
};

class Union {
  vector<Person> people;
  vector<vector<int>> children;
  set<int> choose;

  void dfs(int i) {
    if (choose.find(i) != choose.end())
      return;
    choose.insert(i);
    for (const int &j : children[i])
      dfs(j);
  }

public:
  Union(vector<ll> &skills, vector<ll> &points) {
    unordered_map<ll, Person> dict;
    int n = skills.size();
    for (int i = 0; i < n; ++i) {
      if (dict.find(skills[i]) == dict.end()) {
        dict[skills[i]] = Person{skills[i], points[i], 1};
      } else {
        dict[skills[i]].point += points[i];
        dict[skills[i]].count++;
      }
    }
    for (const auto &p : dict)
      people.emplace_back(p.second);
    int m = people.size();
    children = vector<vector<int>>(m);
    for (int i = 0; i < m - 1; ++i)
      for (int j = i + 1; j < m; ++j) {
        ll si = people[i].skill, sj = people[j].skill;
        ll u = si | sj;
        if (u == si)
          children[i].emplace_back(j);
        else if (u == sj)
          children[j].emplace_back(i);
      }
  }

  ll max_points() {
    ll ans = 0;
    int m = people.size();
    for (int i = 0; i < m; ++i)
      if (people[i].count > 1)
        dfs(i);
    for (const int &i : choose)
      ans += people[i].point;
    return ans;
  }
};

int main() {
  int n;
  cin >> n;
  vector<ll> skills, points;
  for (int i = 0; i < n; ++i) {
    ll a;
    cin >> a;
    skills.emplace_back(a);
  }
  for (int i = 0; i < n; ++i) {
    ll b;
    cin >> b;
    points.emplace_back(b);
  }
  Union u(skills, points);
  cout << u.max_points();

  return 0;
}
