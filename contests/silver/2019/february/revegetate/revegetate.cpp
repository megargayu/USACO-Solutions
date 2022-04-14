#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>

#define MAX_N 100000

using namespace std;

struct Connection
{
  int to;
  bool same;
};

array<vector<Connection>, MAX_N> adj;
array<char, MAX_N> colors;

bool dfs(int v, char color)
{
  colors[v] = color;
  for (const Connection &con : adj[v])
  {
    if (colors[con.to] != '\0')
    {
      if (con.same && color != colors[con.to])
        return false;
      if (!con.same && color == colors[con.to])
        return false;
    }
    else
    {
      if (!dfs(con.to, con.same ? color : (color == '1' ? '2' : '1')))
        return false;
    }
  }

  return true;
}

int main()
{
  ofstream fout("revegetate.out");
  ifstream fin("revegetate.in");

  // figure out number of connected components, and if each are possible to be
  // labelled as 1 or 2 (just label first element as 1 and go from there)

  int N, M;
  fin >> N >> M;

  char c;
  int a, b;
  for (int i = 0; i < M; ++i)
  {
    fin >> c >> a >> b;
    adj[a - 1].push_back({b - 1, c == 'S'});
    adj[b - 1].push_back({a - 1, c == 'S'});
  }

  int numComponents = 0;
  for (int i = 0; i < N; ++i)
    if (colors[i] == '\0')
    {
      ++numComponents;
      if (!dfs(i, '1'))
      {
        fout << "0\n";
        return 0;
      };
    }

  fout << '1';
  for (int i = 0; i < numComponents; ++i)
    fout << '0';
  fout << '\n';

  return 0;
}
