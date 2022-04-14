#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1e5

vector<vector<int>> adj(MAX_N);
vector<int> distL(MAX_N), distK(MAX_N);
queue<int> q;
int ans = 0;

void bfs(vector<int> &dist)
{
  int depth = 0;
  while (!q.empty())
  {
    int size = q.size();

    for (int i = 0; i < size; ++i)
    {
      int v = q.front();
      q.pop();
      dist[v] = depth;

      for (const int &w : adj[v])
      {
        if (dist[w] == 1e9)
        {
          q.push(w);
        }
      }
    }

    ++depth;
  }
}

void dfs(int cur, int par)
{
  for (const int &w : adj[cur])
  {
    if (w == par) continue;
    if (distK[w] >= distL[w])
    {
      ++ans;
      continue;
    }

    dfs(w, cur);
  }
}

int main()
{
  ifstream fin("atlarge.in");
  ofstream fout("atlarge.out");

  int N, K;
  fin >> N >> K;
  --K;

  int a, b;
  for (int i = 0; i < N - 1; ++i)
  {
    fin >> a >> b;
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 0; i < N; ++i)
  {
    if (adj[i].size() == 1)
    {
      q.push(i);
    }
  }

  fill(distL.begin(), distL.end(), 1e9);
  fill(distK.begin(), distK.end(), 1e9);

  bfs(distL);

  q.push(K);
  bfs(distK);

  dfs(K, 0);
  fout << ans << '\n';
}
