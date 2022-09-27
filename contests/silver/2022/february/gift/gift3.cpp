#include <bits/stdc++.h>
using namespace std;

#define MAX_N 500

vector<vector<int>> wishlist(MAX_N, vector<int>(MAX_N));
vector<vector<int>> adj(MAX_N);
vector<vector<int>> canReach(MAX_N, vector<int>(MAX_N, false));
//vector<int> visited(MAX_N);
int N;

void dfs(int from, int cur)
{
  canReach[from][cur] = true;

  for (const int &next : adj[cur])
    if (!canReach[from][next])
      dfs(from, next);
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
    for (int i = 0; i < N && wishlist[cow][i] != cow; ++i)
      adj[cow].push_back(wishlist[cow][i]);

  for (int i = 0; i < N; ++i)
    dfs(i, i);

  for (int cow = 0; cow < N; ++cow)
    for (int i = 0; i < N; ++i)
      if (canReach[wishlist[cow][i]][cow])
      {
        cout << wishlist[cow][i] + 1 << '\n';
        break;
      }
    

  return 0;
}
