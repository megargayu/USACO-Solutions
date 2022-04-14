#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000
#define ll long long

int N, M;
array<int, MAX_N> cows;
array<vector<pair<int, ll>>, MAX_N> adj;
array<int, MAX_N> components;

void dfs(int v, ll w, int component)
{
  components[v] = component;
  for (const auto &adjV : adj[v])
    if (adjV.second >= w && components[adjV.first] == -1)
      dfs(adjV.first, w, component);
}

bool valid(ll w)
{
  int component = 0;
  for (int i = 0; i < N; ++i)
    if (components[i] == -1)
    {
      dfs(i, w, component);
      ++component;
    }

  for (int i = 0; i < N; ++i)
    if (components[i] != components[cows[i]])
      return false;
  
  return true;
}

int main()
{
  ifstream fin("wormsort.in");
  ofstream fout("wormsort.out");

  fin >> N >> M;
  bool sorted = true;
  for (int i = 0; i < N; ++i) 
  { 
    fin >> cows[i];
    --cows[i];
    if (cows[i] != i) sorted = false;
  }
  
  if (sorted)
  {
    fout << "-1\n";
    return 0;
  }

  int a, b, w;
  for (int i = 0; i < M; ++i)
  {
    fin >> a >> b >> w;
    --a, --b;
    adj[a].push_back({ b, w });
    adj[b].push_back({ a, w });
  }

  ll lo = 0, hi = 1000000001, mid, ans;
  while (lo <= hi)
  {
    components.fill(-1);
    mid = lo + (hi - lo) / 2;

    if (valid(mid))
    {
      ans = mid;
      lo = mid + 1;
    } else hi = mid - 1;
  }

  fout << ans << '\n';

  return 0;
}