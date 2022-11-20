#include <bits/stdc++.h>
using namespace std;

#define MAX_N 200

struct Cow
{
  int x, y;
  int dist;
};

vector<Cow> cows(MAX_N);
vector<vector<int>> adj(MAX_N);
vector<bool> vis(MAX_N);
int num;

void dfs(int v)
{
  vis[v] = true;
  ++num;
  for (const auto &w : adj[v])
    if (!vis[w])
      dfs(w);
} 

inline int sq(int x)
{
  return x * x;
}

int main()
{
  freopen("moocast.in", "r", stdin);
  freopen("moocast.out", "w", stdout);

  int N;
  cin >> N;

  for (int i = 0; i < N; ++i)
    cin >> cows[i].x >> cows[i].y >> cows[i].dist;

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
    {
      if (i == j) continue;

      const int dist = sq(cows[j].x - cows[i].x) + sq(cows[j].y - cows[i].y);
      if (dist <= sq(cows[i].dist))
        adj[i].push_back(j);
    }

  int ans = -1;
  for (int i = 0; i < N; ++i)
  {
    fill(vis.begin(), vis.end(), false);
    num = 0;
    dfs(i);
    ans = max(ans, num);
  }

  cout << ans << '\n';

  return 0;
}
