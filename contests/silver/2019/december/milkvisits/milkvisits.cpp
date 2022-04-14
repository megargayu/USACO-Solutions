#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

array<char, MAX_N> flavors;
array<int, MAX_N> components;
array<vector<int>, MAX_N> adj;
int currComponent;

void dfs(int v)
{
  components[v] = currComponent;
  for (const int& adjV : adj[v])
    if (components[adjV] == 0 && flavors[adjV] == flavors[v])
      dfs(adjV);
}

int main()
{
  ifstream fin("milkvisits.in");
  ofstream fout("milkvisits.out");

  int N, M;
  fin >> N >> M;

  for (int i = 0; i < N; ++i)
    fin >> flavors[i];
  
  int a, b;
  for (int i = 0; i < N - 1; ++i)
  {
    fin >> a >> b;
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (currComponent = 1; currComponent <= N; ++currComponent)
    if (components[currComponent] == '\0')
      dfs(currComponent);

  char c;
  for (int i = 0; i < M; ++i)
  {
    fin >> a >> b >> c;
    --a, --b;
    if (components[a] == components[b])
      fout << (c == flavors[a]);
    else fout << 1;
  }

  fout << '\n';

  return 0;
}
