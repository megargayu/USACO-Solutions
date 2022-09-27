// https://cses.fi/problemset/task/1666

#include <iostream>
#include <string>

#include <array>
#include <vector>

using namespace std;

#define MAX_N 100000

array<vector<int>, MAX_N> adj;
array<int, MAX_N> component;
array<int, MAX_N> startOfComponent;
int currComponent = 0;

void dfs(int v)
{
  component[v] = currComponent;

  for (int u : adj[v])
    if (component[u] == 0)
      dfs(u);
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
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 0; i < n; ++i)
    if (component[i] == 0)
    {
      startOfComponent[currComponent] = i;
      ++currComponent;
      dfs(i);
    }

  cout << currComponent - 1 << '\n';
  for (int i = 1; i < currComponent; ++i)
    cout << startOfComponent[i - 1] + 1 << ' ' << startOfComponent[i] + 1 << '\n';

  return 0;
}
