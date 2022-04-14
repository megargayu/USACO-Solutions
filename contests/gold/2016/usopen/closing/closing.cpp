#include <bits/stdc++.h>
using namespace std;

#define MAX 2e5

vector<int> DSU(MAX, -1);
int get(int v)
{
  return DSU[v] < 0 ? v : DSU[v] = get(DSU[v]);
}

int size(int v)
{ 
  return -DSU[get(v)];
}

bool unite(int x, int y)
{
  x = get(x), y = get(y);
  if (x == y) return false;
  if (DSU[x] > DSU[y]) swap(x, y);
  DSU[x] += DSU[y]; DSU[y] = x; return true;
}

vector<vector<int>> adj(MAX);
vector<int> close(MAX);
vector<bool> opened(MAX), result(MAX);
int main()
{
  ifstream fin("closing.in");
  ofstream fout("closing.out");

  int N, M;
  fin >> N >> M;

  int a, b;
  for (int i = 0; i < M; ++i)
  {
    fin >> a >> b;
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 0; i < N; ++i)
    fin >> close[i], --close[i];

  int numComponents = N;
  for (int i = N - 1; i >= 0; --i)
  {
    const int &v = close[i];
    opened[v] = true;

    for (const int &w : adj[v])
      if (opened[w])
        numComponents -= unite(v, w);
    
    result[i] = (numComponents == i + 1);
  }

  for (int i = 0; i < N; ++i) fout << (result[i] ? "YES\n" : "NO\n");

  return 0;
}