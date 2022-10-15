// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/00000000003379bb

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid(31, vector<int>(30));
vector<vector<bool>> adj(27, vector<bool>(27));
vector<int> requirements(27);
vector<bool> vis(27);
string ans;

void dfs(int v)
{
  vis[v] = true;
  if (v != 0)
    ans += (v - 1) + 'A';

  for (int w = 0; w < 27; ++w)
  {
    if (adj[v][w] && !vis[w])
    {
      --requirements[w];

      if (requirements[w] == 0)
        dfs(w);
    }
  }
}

int main()
{
  int T;
  cin >> T;

  int R, C;
  char a;
  int numP;
  for (int t = 1; t <= T; ++t)
  {
    cin >> R >> C;

    ans = "";
    for (int i = 0; i < 27; ++i)
    {
      fill(adj[i].begin(), adj[i].end(), false);
      requirements[i] = 0;
      vis[i] = false;
    }

    numP = 0;
    for (int r = 0; r < R; ++r)
      for (int c = 0; c < C; ++c)
      {
        cin >> a;
        const int num = a - 'A' + 1;
        grid[r][c] = num;

        if (!vis[num])
        {
          vis[num] = true;
          ++numP;
        }
      }

    fill(vis.begin(), vis.end(), false);
    fill(grid[R].begin(), grid[R].begin() + C, 0);

    for (int r = 0; r < R; ++r)
      for (int c = 0; c < C; ++c)
      {
        const int &from = grid[r + 1][c], to = grid[r][c];
        if (from != to && !adj[from][to])
        {
          adj[from][to] = true;
          ++requirements[to];
        }
      }

    dfs(0);

    cout << "Case #" << t << ": " << (numP != ans.size() ? "-1" : ans) << '\n';
  }

  return 0;
}
