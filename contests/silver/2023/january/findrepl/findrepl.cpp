#include <bits/stdc++.h>
using namespace std;

int T;
vector<set<pair<int, bool>>> adj(52);
vector<bool> vis(52, false);
int numUniqueChars;
int ans;
int currLen;
bool isCycle;

int toInt(char c)
{
  if ('a' <= c && c <= 'z')
    return c - 'a';
  else if ('A' <= c && c <= 'Z')
    return c - 'A' + 26;
  else
    throw "invalid character in toInt";
}

void dfs(int v)
{
  vis[v] = true;

  bool hasOut = false;
  for (const auto &w : adj[v])
  {
    if (w.second == true)
      hasOut = true;

    // cout << "from " << v << " to " << w.first << '\n';
    if (!vis[w.first])
      dfs(w.first);
    else if (w.second)
      isCycle = true;
  }

  if (hasOut)
    ++currLen;
}

int main()
{
  cin >> T;

  string a, b;
  while (T--)
  {
    cin >> a >> b;
    for (int i = 0; i < 52; ++i)
      adj[i].clear();
    fill(vis.begin(), vis.end(), false);

    vector<int> has(52, -1);
    bool possible = true;
    for (int i = 0; i < a.size(); ++i)
    {
      if (has[toInt(a[i])] != -1 && has[toInt(a[i])] != toInt(b[i]))
      {
        possible = false;
        break;
      }

      has[toInt(a[i])] = toInt(b[i]);
      if (a[i] != b[i])
      {
        adj[toInt(a[i])].insert({toInt(b[i]), true});
        adj[toInt(b[i])].insert({toInt(a[i]), false});
      }
    }

    if (!possible)
    {
      cout << "-1\n";
      continue;
    }

    numUniqueChars = count(has.begin(), has.end(), true);

    ans = 0;
    for (int i = 0; i < 52; ++i)
      if (adj[i].size() > 0 && !vis[i])
      {
        currLen = 0;
        isCycle = false;
        dfs(i);

        // cout << i << ' ' << isCycle << ' ' << currLen << '\n';

        // need a dummy character
        if (isCycle && numUniqueChars == 52)
        {
          ans = -1;
          break;
        }

        ans += currLen + isCycle;
      }
    cout << ans << '\n';
  }

  return 0;
}