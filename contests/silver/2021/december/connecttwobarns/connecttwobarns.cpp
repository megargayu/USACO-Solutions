#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000
#define INF 2147483647
#define ll long long

array<vector<int>, MAX_N> adj;
array<int, MAX_N> component;
int currComponent = 0;

void dfs(int v)
{
  component[v] = currComponent;
  for (const int &adjV : adj[v])
    if (component[adjV] == -1)
      dfs(adjV);
}

int main()
{
  int T;
  cin >> T;

  int N, M;
  int a, b;

  for (int t = 0; t < T; ++t)
  {
    cin >> N >> M;
    currComponent = 0;
    for (int i = 0; i < N; ++i) adj[i].clear();
    component.fill(-1);

    for (int i = 0; i < M; ++i)
    {
      cin >> a >> b;
      --a, --b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    for (int i = 0; i < N; ++i)
      if (component[i] == -1)
      {
        dfs(i);
        ++currComponent;
      }
    
    // first component -> every other component
    int last0 = 0;
    vector<int> distances;
    distances.resize(currComponent, INF);
    distances[0] = 0;
    for (int i = 0; i < N; ++i)
    {
      if (component[i] == 0) last0 = i;
      distances[component[i]] = min(distances[component[i]], i - last0);
    }

    // now last0 is the last 0 in the whole array, so start at that and go backward
    for (int i = last0; i >= 0; --i)
    {
      if (component[i] == 0) last0 = i;
      distances[component[i]] = min(distances[component[i]], last0 - i);
    }

    // every component -> N
    int lastN = N - 1;
    vector<int> distances2;
    distances2.resize(currComponent, INF);
    distances2[currComponent - 1] = 0;
    for (int i = N - 1; i >= 0; --i)
    {
      if (component[i] == component[N - 1])
        lastN = i;
      distances2[component[i]] = min(distances2[component[i]], lastN - i);
    }

    // now lastN is the first N in the whole array, so start at that and go forward
    for (int i = lastN; i < N; ++i)
    {
      if (component[i] == component[N - 1]) lastN = i;
      distances2[component[i]] = min(distances2[component[i]], i - lastN);
    }

    ll minCost = 1e18;
    for (int i = 0; i < currComponent; ++i)
      minCost = min(minCost, (long long)distances[i] * distances[i] + (long long)distances2[i] * distances2[i]);
    
    cout << minCost << '\n';
  }

  return 0;
}
