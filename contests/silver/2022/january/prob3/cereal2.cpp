#include <bits/stdc++.h>
using namespace std;

#define MAX 1e5
#define pii pair<int, int>
#define f first
#define s second

struct Edge
{
  int id;
  int to;
  bool toFavorite;
};

int N, M;
vector<vector<Edge>> adj(MAX);
vector<bool> visited(MAX), visitedC(MAX), notHungry(MAX);
vector<int> result;

pii getCycle(int prev, int cur)
{
  visitedC[cur] = true;
  for (const Edge& w : adj[cur])
  {
    if (!visitedC[w.to])
    {
      pii r = getCycle(cur, w.to);
      if (r.f != -1) return r;
      continue;
    }

    if (w.to != prev) // don't go back to a vertex we *just* came from
    {
      result.push_back(w.id);
      notHungry[w.id] = true;
      return { w.toFavorite ? w.to : cur, w.id };
    }
  }

  return { -1, -1 };
}

void dfs(int cur, int skip)
{
  visited[cur] = true;
  for (const Edge &w : adj[cur])
    if (!visited[w.to] && w.id != skip)
    {
      notHungry[w.id] = true;
      result.push_back(w.id);
      dfs(w.to, skip);
    }
}

int main()
{
  cin >> N >> M;

  int a, b;
  for (int i = 0; i < N; ++i)
  {
    cin >> a >> b;
    --a, --b;
    adj[a].push_back({ i, b, false });
    adj[b].push_back({ i, a, true });
  }

  for (int i = 0; i < N; ++i)
    if (!visited[i])
    {
      pii cycle = getCycle(-1, i);
      dfs(cycle.f == -1 ? i : cycle.f, cycle.s);
    }

  int hungry = 0;
  for (int i = 0; i < N; ++i)
    if (!notHungry[i])
    {
      ++hungry;
      result.push_back(i);
    }

  cout << hungry << '\n';
  for (int i = 0; i < N; ++i)
    cout << result[i] + 1 << '\n';

  return 0;
}