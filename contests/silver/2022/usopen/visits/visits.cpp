#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ll long long

vector<pii> adj(1e5);
vector<bool> visited(1e5), visited2(1e5);
int least = 2e9;
int cycleStart = -1;
ll sum = 0;

bool found = false;

void dfs(int v)
{
  visited[v] = true;

  if (!visited[adj[v].first])
    dfs(adj[v].first);
  else
  {
    // this is a cycle!
    // if (cycleStart != -1) throw "";
    cycleStart = adj[v].first;
  }
}

void dfs2(int v)
{
  visited2[v] = true;
  least = min(least, adj[v].second);
  //cout << "VERTEX: " << v << '\n';
  if (!visited2[adj[v].first])
    dfs2(adj[v].first);
  else
    found = (adj[v].first == cycleStart);
}

int main()
{
  int N;
  cin >> N;

  for (int i = 0; i < N; ++i)
  {
    cin >> adj[i].first >> adj[i].second;
    --adj[i].first;
    sum += adj[i].second;
  }

  // find cycle
  for (int i = 0; i < N; ++i)
  {
    if (!visited[i])
    {
      cycleStart = -1;
      dfs(i);

      //if (cycleStart == -1) throw "";

      if (cycleStart != -1)
      {
        // find smallest edge in cycle
        least = 2e9;
        //cout << cycleStart << '\n';
        found = false;
        dfs2(cycleStart);
        if (found)
          sum -= least;
      }
    }
  }

  cout << sum << '\n';

  return 0;
}
