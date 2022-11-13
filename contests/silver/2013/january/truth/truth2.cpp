#include <bits/stdc++.h>
using namespace std;

struct Edge
{
  char c;
  int i;
};

#define MAX_N 1000

vector<map<int, Edge>> adj(MAX_N);
vector<char> color(MAX_N);
int A;

bool dfs(int v)
{
  // cout << "in " << v << '\n';
  for (const auto &conn : adj[v])
  {
    if (conn.second.i > A)
      continue;

    if (color[conn.first] == '\0')
    {
      // liars are colored opposite
      if (conn.second.c == 'L')
        color[conn.first] = color[v] == 'r' ? 'b' : 'r';
      // truths are colored the same
      else
        color[conn.first] = color[v];

      if (!dfs(conn.first))
        return false;
    }
    else
    {
      // check if this connection is valid
      if (adj[v][conn.first].c == 'L' ? (color[v] == color[conn.first]) : (color[v] != color[conn.first]))
      {
        // cout << color[v] << ' ' << color[w] << '\n';
        // cout << v << ' ' << w << '\n';
        return false;
      }
    }
  }

  return true;
}

int main()
{
  freopen("truth.in", "r", stdin);
  freopen("truth.out", "w", stdout);

  int N, M;
  cin >> N >> M;

  int lo = 0, hi = M - 1, ans = 0;

  int a, b;
  char c;
  for (int i = 0; i < M; ++i)
  {
    cin >> a >> b >> c;
    --a, --b;

    const auto foundA = adj[a].find(b), foundB = adj[b].find(a);
    if ((foundA != adj[a].end() && foundA->second.c != c) ||
        (foundB != adj[b].end() && foundB->second.c != c))
      hi = min(hi, i - 1);
    
    if (foundA == adj[a].end() && foundB == adj[b].end())
    {
      adj[a][b] = {c, i};
      adj[b][a] = {c, i};
    }
  }

  // cout << hi << '\n';

  while (lo <= hi)
  {
    A = lo + (hi - lo) / 2;
    // cout << A << '\n';
    fill(color.begin(), color.begin() + N, '\0');

    bool works = true;
    for (int v = 0; v < N; ++v)
      if (color[v] == '\0')
      {
        color[v] = 'r';
        if (!dfs(v))
        {
          works = false;
          break;
        }
      }
    
    if (works)
    {
      ans = A + 1;
      lo = A + 1;
    }
    else
      hi = A - 1;
  }

  cout << ans << '\n';

  return 0;
}