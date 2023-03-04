/*
ID: megarga1
TASK: butter
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 500
#define MAX_P 800
#define MAX_C 1450
#define INF 1000000000
#define pii pair<int, int>

int N, P, C;
vector<int> cows(MAX_N);
vector<vector<pair<int, int>>> adj(MAX_C);
// dist of each pasture to each other pasture
vector<int> dist(MAX_P);

void dijkstra(int start)
{
  vector<bool> seen(MAX_P, false);
  priority_queue<pii, vector<pii>, greater<pii>> q;
  fill(dist.begin(), dist.begin() + P, INF);

  q.push({0, start});

  dist[start] = 0;
  while (!q.empty())
  {
    const auto v = q.top().second;
    q.pop();

    if (seen[v])
      continue;
    seen[v] = true;

    for (const auto p : adj[v])
    {
      const auto [b, w] = p;
      if (dist[v] + w < dist[b])
      {
        dist[b] = dist[v] + w;
        q.push({dist[b], b});
      }
    }
  }
}

int main()
{
  freopen("butter.in", "r", stdin);
  freopen("butter.out", "w", stdout);

  cin >> N >> P >> C;
  for (int i = 0; i < N; ++i)
  {
    cin >> cows[i];
    --cows[i];
  }

  int a, b, w;
  for (int i = 0; i < C; ++i)
  {
    cin >> a >> b >> w;
    --a, --b;
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
  }

  int ans = INF;
  for (int i = 0; i < P; ++i)
  {
    // what if we put the butter in this pasture?
    dijkstra(i);

    int curr = 0;
    for (int j = 0; j < N; ++j)
      curr += dist[cows[j]];

    ans = min(curr, ans);
  }

  cout << ans << '\n';

  return 0;
}
