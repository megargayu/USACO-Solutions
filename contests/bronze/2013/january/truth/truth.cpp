#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000
#define MAX_M 10000

struct Edge
{
  int a, b;
  char c;
};

// NOTE: times out (use truth2.cpp with binary search)

vector<Edge> edges(MAX_M);

vector<unordered_set<int>> connections(MAX_N);
vector<vector<char>> adj(MAX_N, vector<char>(MAX_N, '\0'));

vector<bool> vis(MAX_N);
vector<bool> color(MAX_N);

bool dfs(int v)
{
  vis[v] = true;
  for (const int w : connections[v])
    if (!vis[w])
    {
      // liars are colored opposite
      if (adj[v][w] == 'L')
        color[w] = !color[v];
      // truths are colored the same
      else
        color[w] = color[v];

      if (!dfs(w))
        return false;
    }
    else
    {
      // make sure our adj list makes sense
      if (adj[v][w] == 'L' ? (color[v] == color[w]) : (color[v] != color[w]))
      {
        // cout << color[v] << ' ' << color[w] << '\n';
        // cout << v << ' ' << w << '\n';
        return false;
      }
    }

  return true;
}

int main()
{
  // freopen("truth.in", "r", stdin);
  // freopen("truth.out", "w", stdout);

  int N, M;
  cin >> N >> M;

  for (int i = 0; i < M; ++i)
  {
    cin >> edges[i].a >> edges[i].b >> edges[i].c;
    --edges[i].a;
    --edges[i].b;
  }

  for (int i = 0; i < M; ++i)
  {
    const int &a = edges[i].a, &b = edges[i].b;
    const char &c = edges[i].c;
    if ((adj[a][b] != '\0' && adj[a][b] != c) ||
        (adj[b][a] != '\0' && adj[b][a] != c))
    {
      cout << i << '\n';
      return 0;
    }

    adj[a][b] = c;
    adj[b][a] = c;
    connections[a].insert(b);
    connections[b].insert(a);
    fill(vis.begin(), vis.end(), false);

    for (int v = 0; v < N; ++v)
    {
      if (vis[v])
        continue;

      // this is a new component, so it doesn't matter if the color
      // starts as red or black
      color[v] = true;
      if (!dfs(v))
      {
        cout << i << '\n';
        return 0;
      }
    }
  }

  cout << M << '\n';

  return 0;
}