/*
ID: megarga1
TASK: fence
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX_F 1024

int F;
vector<vector<int>> adj(MAX_F, vector<int>(MAX_F, 0));
vector<int> degree(MAX_F, 0);
vector<int> result(MAX_F + 1);
int curpos;

void findCircuit(int v)
{
  if (degree[v] == 0)
  {
    result[curpos] = v;
    ++curpos;
    return;
  }

  while (degree[v] > 0)
  {
    int w;
    for (int i = 0; i < MAX_F; ++i)
      if (adj[v][i])
      {
        w = i;
        break;
      }

    // cout << v << ' ' << w << '\n';

    --adj[v][w], --adj[w][v];
    --degree[v], --degree[w];
    findCircuit(w);
  }

  result[curpos] = v;
  ++curpos;
}

int main()
{
  freopen("fence.in", "r", stdin);
  freopen("fence.out", "w", stdout);

  cin >> F;
  int a, b;
  for (int i = 0; i < F; ++i)
  {
    cin >> a >> b;
    --a, --b;
    ++adj[a][b], ++adj[b][a];
    ++degree[a], ++degree[b];
  }

  curpos = -1;
  for (int i = 0; i < MAX_F; ++i)
    if (degree[i] % 2 == 1)
    {
      curpos = 0;
      // cout << "start at " << i << endl;
      findCircuit(i);
      break;
    }

  // no odd-degreed nodes, just start from any node with a connection
  if (curpos == -1)
  {
    for (int i = 0; i < MAX_F; ++i)
      if (degree[i] > 0)
      {
        curpos = 0;
        // cout << "start at " << i << endl;
        findCircuit(i);
        break;
      }
  }


  // assert(curpos == F + 1);

  for (int i = F; i >= 0; --i)
    cout << result[i] + 1 << '\n';

  return 0;
}
