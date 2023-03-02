/*
ID: megarga1
TASK: msquare
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

#define INF 2e8

const array<array<int, 8>, 3> transformations{{{4, 5, 6, 7, 0, 1, 2, 3},
                                               {3, 0, 1, 2, 7, 4, 5, 6},
                                               {0, 5, 1, 3, 4, 6, 2, 7}}};

string target = "";

queue<pair<string, int>> q;
set<string> seen;
map<int, pair<char, int>> val;

string transform(string s, int m)
{
  assert(0 <= m && m <= 2);

  string newS = "";
  for (int i = 0; i < 8; ++i)
    newS += s[transformations[m][i]];

  return newS;
}

string backtrace(int id, const map<int, pair<char, int>> &val)
{
  string sofar = "";
  int currid = id;
  while (true)
  {
    auto currval = val.find(currid);
    assert(currval != val.end());

    auto [lastChar, parent] = currval->second;

    if (parent == -1)
      break;

    sofar += lastChar;
    currid = parent;
  }

  reverse(sofar.begin(), sofar.end());

  return sofar;
}

string bfs()
{
  q.push({"12348765", 0});
  val[0] = {'\0', -1};
  seen.insert("12348765");

  int lastId = 0;
  while (!q.empty())
  {
    auto [curr, id] = q.front();

    if (curr == target)
      return backtrace(id, val);

    for (int i = 0; i < 3; ++i)
    {
      string newS = transform(curr, i);
      if (seen.find(newS) == seen.end())
      {
        ++lastId;
        val[lastId] = {i + 'A', id};
        q.push({newS, lastId});
        seen.insert(newS);
      }
    }

    q.pop();
  }

  return "";
}

int main()
{
  freopen("msquare.in", "r", stdin);
  freopen("msquare.out", "w", stdout);

  int a;
  for (int i = 0; i < 8; ++i)
  {
    cin >> a;
    target += (a + '0');
  }

  reverse(target.begin() + 4, target.end());

  // cout << transform("12348765", 1) << '\n';

  string ans = bfs();
  cout << ans.size() << '\n'
       << ans << '\n';

  return 0;
}
