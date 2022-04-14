#include <bits/stdc++.h>
using namespace std;

#define MAX 1e5
#define INF 2000000
#define ll long long

vector<vector<int>> adj(MAX);
vector<int> component(MAX);
vector<ll> dist0(MAX), distN(MAX);
int currComponent = 0;

void dfs(int v)
{
  component[v] = currComponent;
  for (const int &w : adj[v])
    if (component[w] == -1)
      dfs(w);
}

int main() {
  int T;
  cin >> T;

  int N, M, a, b;
  for (int t = 0; t < T; ++t)
  {
    cin >> N >> M;

    for (int i = 0; i < N; ++i) adj[i].clear();
    currComponent = 0;
    
    for (int i = 0; i < M; ++i)
    {
      cin >> a >> b;
      --a, --b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    fill(component.begin(), component.end(), -1);
    fill(dist0.begin(), dist0.end(), INF);
    fill(distN.begin(), distN.end(), INF);

    for (int i = 0; i < N; ++i)
      if (component[i] == -1)
      {
        dfs(i);
        ++currComponent;
      }

    int lastComponent = currComponent - 1;
    
    dist0[0] = 0;
    int last = -1;
    for (int i = 0; i < N; ++i)
    {
      if (component[i] == 0) last = i;
      else if (last != -1)
      {
        dist0[component[i]] = min(dist0[component[i]], static_cast<ll>(i - last));
      }
    }

    last = -1;
    for (int i = N - 1; i >= 0; --i)
    {
      if (component[i] == 0) last = i;
      else if (last != -1)
      {
        dist0[component[i]] = min(dist0[component[i]], static_cast<ll>(last - i));
      }
    }

    distN[lastComponent] = 0;
    last = -1;
    for (int i = 0; i < N; ++i)
    {
      if (component[i] == lastComponent) last = i;
      else if (last != -1)
      {
        distN[component[i]] = min(distN[component[i]], static_cast<ll>(i - last));
      }
    }

    last = -1;
    for (int i = N - 1; i >= 0; --i)
    {
      if (component[i] == lastComponent) last = i;
      else if (last != -1)
      {
        distN[component[i]] = min(distN[component[i]], static_cast<ll>(last - i));
      }
    }

    ll ans = INF;
    for (int i = 0; i < lastComponent + 1; ++i)
    {
      ans = min(ans, dist0[i] * dist0[i] + distN[i] * distN[i]);
    }

    if (ans == 1) 
    cout << "bruh\n";

    cout << ans << '\n';
  }

  return 0;
}
