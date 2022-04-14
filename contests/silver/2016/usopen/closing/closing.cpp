#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <queue>

using namespace std;

#define MAX_N 3000

array<vector<int>, MAX_N> adj;
array<bool, MAX_N> removed{};

int dfs(int v, array<bool, MAX_N> &visited)
{
  visited[v] = true;
  int connected{1};
  for (int connection : adj[v])
    if (!visited[connection] && !removed[connection])
      connected += dfs(connection, visited);
  return connected;
}

int main()
{
  ofstream fout("closing.out");
  ifstream fin("closing.in");

  int N, M;
  fin >> N >> M;

  for (int i{0}; i < M; ++i)
  {
    int a, b;
    fin >> a >> b;
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }

  for (int i{0}; i < N; ++i)
  {
    if (i > 0)
    {
      int toRemove;
      fin >> toRemove;
      removed[toRemove - 1] = true;
    }

    int open{0};
    for (; open < N && removed[open]; ++open)
      ;

    array<bool, MAX_N> visited{};
    int connectedWith{dfs(open, visited)};
    fout << (connectedWith == N - i ? "YES" : "NO") << '\n';
  }

  return 0;
}
