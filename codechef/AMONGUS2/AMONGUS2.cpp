// https://www.codechef.com/INOIPRAC/problems/AMONGUS2

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 500000

// "red" is true, "black" is false
vector<bool> colors(MAX_N);
vector<bool> vis(MAX_N, false);
vector<vector<pair<int, int>>> adj(MAX_N);

int numRed, numBlack;
bool valid;

void dfs(int v)
{
  vis[v] = true;

  if (colors[v])
    ++numRed;
  else
    ++numBlack;

  for (int i = 0; i < adj[v].size(); ++i)
  {
    const int &w = adj[v][i].first;
    const int &type = adj[v][i].second;

    bool newColor;
    if (type == 1) // v accuses w of being a parasite
      newColor = !colors[v];
    else // v vouches that w is a human
      newColor = colors[v];

    if (vis[w])
    {
      // validate (check if answer is -1)
      if (colors[w] != newColor)
        valid = false;
    }
    else
    {
      colors[w] = newColor;
      dfs(w);
    }
  }
}

int main()
{
  int T;
  cin >> T;

  for (int t = 0; t < T; ++t)
  {
    int N, Q;
    cin >> N >> Q;

    fill(vis.begin(), vis.end(), false);
    for (int i = 0; i < N; ++i)
      adj[i].clear();

    int type, a, b;
    for (int i = 0; i < Q; ++i)
    {
      cin >> type >> a >> b;
      --a, --b;
      adj[a].push_back({b, type});
      adj[b].push_back({a, type});
    }

    int ans = 0;
    for (int i = 0; i < N; ++i)
      if (!vis[i])
      {
        colors[i] = true;
        numRed = 0, numBlack = 0;
        valid = true;
        dfs(i);

        if (!valid)
        {
          ans = -1;
          break;
        }

        ans += max(numRed, numBlack);
      }

    cout << ans << '\n';
  }

  return 0;
}
