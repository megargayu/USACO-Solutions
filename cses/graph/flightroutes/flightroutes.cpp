// https://cses.fi/problemset/task/1682

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1e5

struct Edge
{
  int to;
  bool forward;
};

vector<vector<Edge>> adj(MAX_N);
vector<bool> vis(MAX_N);
bool toCheck;

void dfs(int v)
{
  vis[v] = true;
  for (const Edge &w : adj[v])
    if (!vis[w.to] && w.forward == toCheck)
      dfs(w.to);
}

int main()
{
  // check if G is a strongly connected component
  int n, m;
  cin >> n >> m;
  
  int a, b;
  for (int i = 0; i < m; ++i)
  {
    cin >> a >> b;
    --a, --b;
    adj[a].push_back({b, true});
    adj[b].push_back({a, false});
  }

  toCheck = true;
  dfs(0);

  for (int i = 0; i < n; ++i)
    if (!vis[i])
    {
      cout << "NO\n1 " << i + 1 << '\n';
      return 0;
    }
  
  fill(vis.begin(), vis.end(), false);
  toCheck = false;
  dfs(0);

  for (int i = 0; i < n; ++i)
    if (!vis[i])
    {
      cout << "NO\n" << i + 1 << " 1\n";
      return 0;
    }
  
  cout << "YES\n";

  return 0;
}
