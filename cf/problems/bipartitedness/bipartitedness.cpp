// https://codeforces.com/contest/862/problem/B

#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

#define MAX_N 100000

const array<char, 2> colorMap{'A', 'B'};

array<vector<int>, MAX_N> adj;
array<char, MAX_N> colors;
array<long long, 2> numCol;

void dfs(int v, bool c)
{
  colors[v] = colorMap[c];
  ++numCol[c];

  for (const int &adjV : adj[v])
    if (colors[adjV] == '\0')
      dfs(adjV, !c);
}

int main()
{
  int n;
  cin >> n;

  int u, v;
  for (int i = 0; i < n - 1; ++i)
  {
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 0; i < n; ++i)
    if (colors[i] == '\0')
      dfs(i, true);

  cout << numCol[0] * numCol[1] - (n - 1) << '\n';

  return 0;
}
