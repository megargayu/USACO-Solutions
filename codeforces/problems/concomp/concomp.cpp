// https://codeforces.com/problemset/problem/920/E

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 200000

vector<set<int>> reverseAdj(MAX_N);
vector<int> numInComp(MAX_N, 0);
set<int> unvisited;

int currComp = 0;

inline bool connected(int v, int w)
{
  // it's connected if it's not not connected
  return reverseAdj[v].find(w) == reverseAdj[v].end();
}

void dfs(int v)
{
  unvisited.erase(v);
  //cout << v << " is in " << currComp << '\n';
  ++numInComp[currComp];

  auto curr = unvisited.begin();
  while (curr != unvisited.end())
  {
    int w = *curr;
    if (!connected(v, w))
    {
      ++curr;
      continue;
    }

    dfs(w);
    curr = unvisited.upper_bound(w);
  }
}

int main()
{
  int n, m;
  cin >> n >> m;

  int a, b;
  for (int i = 0; i < m; ++i)
  {
    cin >> a >> b;
    --a, --b;
    reverseAdj[a].insert(b);
    reverseAdj[b].insert(a);
  }

  for (int i = 0; i < n; ++i)
    unvisited.insert(i);

  while (!unvisited.empty())
  {
    dfs(*unvisited.begin());
    ++currComp;
  }

  sort(numInComp.begin(), numInComp.begin() + currComp);

  cout << currComp << '\n';
  for (int i = 0; i < currComp; ++i)
    cout << numInComp[i] << ' ';
  cout << '\n';

  return 0;
}