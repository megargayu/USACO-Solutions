/*
ID: megarga1
TASK: milk3
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> maxmilk(3);
vector<vector<vector<bool>>> seen(21, vector<vector<bool>>(21, vector<bool>(21)));
vector<bool> finalval(21);

void dfs(vector<int> vals)
{
  seen[vals[0]][vals[1]][vals[2]] = true;
  if (vals[0] == 0)
    finalval[vals[2]] = true;

  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
    {
      if (i == j)
        continue;

      vector<int> newVals = vals;
      // pour from i -> j
      newVals[j] = min(maxmilk[j], newVals[j] + vals[i]);
      newVals[i] -= newVals[j] - vals[j];

      if (!seen[newVals[0]][newVals[1]][newVals[2]])
        dfs(newVals);
    }
}

int main()
{
  freopen("milk3.in", "r", stdin);
  freopen("milk3.out", "w", stdout);

  cin >> maxmilk[0] >> maxmilk[1] >> maxmilk[2];

  dfs({0, 0, maxmilk[2]});

  bool printed = false;
  for (int i = 0; i <= 20; ++i)
    if (finalval[i])
    {
      if (printed)
        cout << ' ';
      cout << i;

      if (!printed)
        printed = true;
    }
  cout << '\n';

  return 0;
}
