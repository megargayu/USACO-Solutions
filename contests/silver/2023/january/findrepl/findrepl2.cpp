#include <bits/stdc++.h>
using namespace std;

int toInt(char c)
{
  if ('a' <= c && c <= 'z')
    return c - 'a';
  else if ('A' <= c && c <= 'Z')
    return c - 'A' + 26;
  else
    throw "invalid character in toInt";
}


void dfs(int v, vector<bool> &vis, vector<int> &onStack, vector<vector<int>> &adj)
{
  // detect cycle
  vis[v] = onStack[v] = true;

  for (const int &w : adj[v])
    if (!vis[w] && )

  onStack[v] = false;
}

int solve()
{
  string a, b;
  cin >> a >> b;

  vector<vector<int>> adj(52);
  vector<int> goesTo(52, -1);
  vector<int> incoming(52, 0); // # of incoming edges from each letter
  int ans = 0;
  for (int i = 0; i < a.size(); ++i)
  {
    int ai = toInt(a[i]), bi = toInt(b[i]);
    
    if (goesTo[ai] != -1 && goesTo[ai] != bi)
      return -1;
    
    goesTo[ai] = bi;
    if (ai != bi) // don't want to store self loops!
    {
      adj[ai].push_back(bi);
      ++ans; // answer = # of connections + # of cycles
      ++incoming[bi]; // add to incoming of b (since the connection is from a -> b)
    }
  }

  vector<bool> vis(52);
  stack<int> curr;

}

int main()
{
  int T;
  cin >> T;

  while (T--)
    cout << solve() << '\n';
  
  return 0;
}
