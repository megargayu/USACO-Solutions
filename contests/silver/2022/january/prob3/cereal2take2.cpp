// I forgot how to solve this, so I decided to re-try it after competition.

#include <bits/stdc++.h>
using namespace std;

#define MAX 1e5

vector<pair<int, int>> cereal(MAX);
vector<vector<pair<int, int>>> adj(MAX);
vector<bool> globalVis(MAX, false), vis(MAX);

int main()
{
  int N, M;
  cin >> N >> M;

  int a, b;
  for (int i = 0; i < N; ++i)
  {
    cin >> a >> b;
    --a, --b;
    cereal[i] = {a, b};
    adj[a].push_back({b, i});
    adj[b].push_back({a, i});
  }

  vector<int> ans;
  for (int c = 0;;)
  {

    // step 1. find an extra edge in the tree
    int extraEdge = -1;
    const std::function<void(int, int)> findExtraEdge = [&](int from, int v)
    {
      vis[v] = true;
      globalVis[v] = true;
      for (int i = 0; i < adj[v].size(); ++i)
      {
        const int &w = adj[v][i].first;
        const int &wI = adj[v][i].second;

        if (!vis[w])
          findExtraEdge(v, w);
        else if (w != from && extraEdge == -1) // double-count this edge
          extraEdge = wI;
      }
    };

    fill(vis.begin(), vis.begin() + M, false);
    findExtraEdge(-1, c);

    // step 2. run a depth first search through the tree to get the order
    const int root = extraEdge == -1 ? c : cereal[extraEdge].first;

    if (extraEdge != -1)
      ans.push_back(extraEdge);

    const std::function<void(int)> dfs = [&](int v)
    {
      vis[v] = true;
      for (int i = 0; i < adj[v].size(); ++i)
      {
        const int &w = adj[v][i].first;
        const int &wI = adj[v][i].second;

        if (!vis[w] && wI != extraEdge)
        {
          ans.push_back(wI); 
          dfs(w);
        }
      }
    };

    fill(vis.begin(), vis.begin() + M, false);
    dfs(root);

    // step 3. continue to next connected component
    bool found = false;
    for (int i = 0; i < M; ++i)
      if (!globalVis[i])
      {
        c = i;
        found = true;
        break;
      }
    
    if (!found)
      break;
  }

  // step 4. find hungry cows and add them to end of answer
  set<int> ansSet;
  for (int i = 0; i < ans.size(); ++i)
    ansSet.insert(ans[i]);
  
  int hungryCows = N - ansSet.size();

  for (int i = 0; i < N; ++i)
    if (ansSet.find(i) == ansSet.end())
      ans.push_back(i);
  
  // step 5. output answer
  cout << hungryCows << '\n';

  for (int i = 0; i < N; ++i)
    cout << ans[i] + 1 << '\n';

  return 0;
}
