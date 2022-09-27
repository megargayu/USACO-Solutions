#include <bits/stdc++.h>
using namespace std;

#define MAX_N 500

vector<vector<int>> wishlist(MAX_N, vector<int>(MAX_N));
vector<vector<int>> adj(MAX_N);
vector<int> visited(MAX_N);
int N, cow;
bool possible = false;

void dfs(int v)
{
  if (v == cow) possible = true;
  if (possible) return;
  visited[v] = true;

  for (const int &w : adj[v])
    if (!visited[w])
      dfs(w);
}

int main()
{
  cin >> N;

  int a;
  for (int cow = 0; cow < N; ++cow)
    for (int i = 0; i < N; ++i)
    {
      cin >> wishlist[cow][i];
      --wishlist[cow][i];
    }

  for (int cow = 0; cow < N; ++cow)
  {
    for (int i = 0; i < N && wishlist[cow][i] != cow; ++i)
    {
      adj[cow].push_back(wishlist[cow][i]);
    }
  }

  for (cow = 0; cow < N; ++cow)
  {
    possible = false;
    for (int i = 0; i < N && wishlist[cow][i] != cow; ++i)
    {
      fill(visited.begin(), visited.end(), false);
      dfs(wishlist[cow][i]);
      if (possible)
      {
        cout << wishlist[cow][i] + 1 << '\n';
        break;
      }
    }

    if (!possible) cout << cow + 1 << '\n';
  }

  return 0;
}
