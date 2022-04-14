// https://cses.fi/problemset/result/3373051/

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 200000

vector<vector<int>> adj(MAX_N);
vector<int> ans(MAX_N);

int dfsSize(int v)
{
  int size = 0;
  for (const int &w : adj[v])
    size += dfsSize(w) + 1;

  ans[v] = size;
  return size;
}

int main()
{
  int N;
  cin >> N;

  int boss;
  for (int i = 1; i < N; ++i)
  {
    cin >> boss;
    --boss;
    adj[boss].push_back(i);
  }

  dfsSize(0);

  for (int i = 0; i < N; ++i)
  {
    cout << ans[i];
    if (i < N - 1) cout << ' ';
  }
  cout << '\n';

  return 0;
}
