// https://open.kattis.com/problems/birthday

#include <bits/stdc++.h>
using namespace std;

#define MAX_P 105

int p, c;
vector<pair<int, int>> connections(5000);
vector<vector<bool>> adj(MAX_P, vector<bool>(MAX_P));
vector<bool> vis(MAX_P);

void dfs(int v)
{
  vis[v] = true;
  for (int w = 0; w < p; ++w)
    if (adj[v][w] && !vis[w])
      dfs(w);
}

int main()
{
  int a, b;
  while (true)
  {
    cin >> p >> c;
    if (p == 0 && c == 0)
      break;

    for (int i = 0; i < MAX_P; ++i)
      fill(adj[i].begin(), adj[i].end(), false);
    
    for (int i = 0; i < c; ++i)
    {
      cin >> a >> b;
      connections[i] = {a, b};
      adj[a][b] = true;
      adj[b][a] = true;
    }

    bool valid = true;
    for (int i = 0; i < c; ++i)
    {
      const auto &conn = connections[i];
      adj[conn.first][conn.second] = false;
      adj[conn.second][conn.first] = false;

      fill(vis.begin(), vis.end(), false);
      dfs(0);

      for (int j = 0; j < p; ++j)
        if (!vis[j])
        {
          valid = false;
          break;
        }
      
      if (!valid) break;

      adj[conn.first][conn.second] = true;
      adj[conn.second][conn.first] = true;
    }

    cout << (valid ? "No\n" : "Yes\n");
  }

  return 0;
}