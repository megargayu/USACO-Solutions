#include <iostream>
#include <string>

#include <array>
#include <vector>

using namespace std;

#define MAX_N 100000

array<vector<int>, MAX_N> adj;
array<char, MAX_N> colors{}; // \\0 == unvisited

int dfs(int v, bool color)
{
  colors[v] = color ? '2' : '1';

  for (int u : adj[v])
  {
    if (colors[u] == '\0')
    {
      if (!dfs(u, !color))
        return false;
    }
    else if ((colors[u] == '1' && !color) || (colors[u] == '2' && color))
      return false;
  }

  return true;
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
    if (colors[i] == '\0')
    {
      if (!dfs(i, false))
      {
        cout << "IMPOSSIBLE\n";
        return 0;
      }
    }

  for (int i = 0; i < n - 1; ++i)
    cout << colors[i] << ' ';
  cout << colors[n - 1] << '\n';

  return 0;
}
