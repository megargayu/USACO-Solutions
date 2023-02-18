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

int cycleStart;
vector<int> inCycle;

bool dfs(int v, vector<bool> &vis, vector<bool> &onStack, vector<int> &adj)
{
  // TODO: only return cycle, not the whole stack!
  vis[v] = onStack[v] = true;

  if (adj[v] == -1)
  {
    onStack[v] = false;
    return false;
  }

  if (onStack[adj[v]])
  {
    cycleStart = adj[v];
    inCycle.push_back(v);
    onStack[v] = false;
    return true;
  }
  else if (!vis[adj[v]])
  {
    if (dfs(adj[v], vis, onStack, adj))
    {
      if (inCycle.size() == 0 || inCycle[inCycle.size() - 1] != cycleStart)
        inCycle.push_back(v);

      onStack[v] = false;
      return true;
    }
  }

  onStack[v] = false;
  return false;
}

int solve()
{
  string a, b;
  cin >> a >> b;

  vector<int> adj(52, -1);
  vector<int> incoming(52, 0); // # of incoming edges from each letter
  int ans = 0;
  for (int i = 0; i < a.size(); ++i)
  {
    int ai = toInt(a[i]), bi = toInt(b[i]);

    if (adj[ai] != -1 && adj[ai] != bi)
      return -1;

    // if adj[ai] is not -1, we know it's already bi
    if (adj[ai] == -1)
    {
      adj[ai] = bi;
      ++ans;          // answer = # of connections + # of cycles
      ++incoming[bi]; // add to incoming of b (since the connection is from a -> b)
    }
  }

  vector<bool> tmpSeen(52, false);
  for (int i = 0; i < b.size(); ++i)
    tmpSeen[toInt(b[i])] = true;
  
  if (count(tmpSeen.begin(), tmpSeen.end(), true) == 52 && a != b)
    return -1;

  // remove all self loops
  for (int i = 0; i < 52; ++i)
    if (adj[i] == i)
    {
      adj[i] = -1;
      --ans;
      --incoming[i];
    }

  vector<bool> vis(52, false);
  vector<bool> onStack(52, false);

  for (int i = 0; i < 52; ++i)
    if (!vis[i])
    {
      inCycle.clear();
      bool cycle = dfs(i, vis, onStack, adj);
      if (cycle)
      {
        // check if this cycle is valid
        for (const int &w : inCycle)
        {
          // since we have an extra node protruding from this cycle, we can use that as a dummy character instead
          if (incoming[w] > 1)
          {
            cycle = false;
            break;
          }
        }
      }

      ans += cycle;
    }

  return ans;
}

int main()
{
  int T;
  cin >> T;

  while (T--)
    cout << solve() << '\n';

  return 0;
}
