// https://codeforces.com/contest/919/problem/D

#include <bits/stdc++.h>
using namespace std;

#define MAX_NM 300000

int n, m;
string s;

vector<vector<int>> adj(MAX_NM);
vector<bool> vis(MAX_NM, false), cycle_stack(MAX_NM, false);
vector<vector<int>> max_let(MAX_NM, vector<int>(26, 0));

bool cycle = false;

void update_max(int v, int w)
{
  for (int i = 0; i < 26; ++i)
    max_let[v][i] = max(max_let[v][i], max_let[w][i]);
}

void dfs(int v)
{
  vis[v] = true;
  cycle_stack[v] = true;

  for (const int &w : adj[v])
  {
    if (!vis[w])
      dfs(w);
    else if (cycle_stack[w])
      cycle = true;

    update_max(v, w);
  }

  cycle_stack[v] = false;
  ++max_let[v][s[v] - 'a'];
}

int main()
{
  cin >> n >> m;
  cin >> s;

  int a, b;
  for (int i = 0; i < m; ++i)
  {
    cin >> a >> b;
    --a, --b;
    adj[a].push_back(b);
  }

  for (int i = 0; i < n; ++i)
    if (!vis[i])
      dfs(i);

  if (cycle)
  {
    cout << "-1\n";
    return 0;
  }

  int max_val = 0;
  for (int i = 0; i < n; ++i)
    for (int l = 0; l < 26; ++l)
      max_val = max(max_val, max_let[i][l]);
  
  cout << max_val << '\n';

  return 0;
}
