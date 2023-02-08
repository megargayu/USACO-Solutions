// too slow

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1500

int N;

const vector<int> dr{1, 0},
                  dc{0, 1};

// 0 = D, 1 = R
vector<vector<int>> grid(MAX_N + 1, vector<int>(MAX_N + 1));
vector<vector<bool>> vis(MAX_N, vector<bool>(MAX_N));

int ans;

int floodfill(int i, int j)
{  
  bool firstVis = !vis[i][j];
  vis[i][j] = true;

  int nr = i + dr[grid[i][j]], nc = j + dc[grid[i][j]];
  if (nr == N || nc == N) // vat
  {
    if (firstVis)
      ans += grid[nr][nc];
    // cout << i << ' ' << j << ' ' << grid[nr][nc] << '\n';
    return grid[nr][nc];
  }
  else
  {
    int val = floodfill(nr, nc);
    // cout << i << ' ' << j << ' ' << val << '\n';
    if (firstVis)
      ans += val;
    return val;
  }

}

int floodfill()
{
  ans = 0;

  for (int i = 0; i < N; ++i)
    fill(vis[i].begin(), vis[i].end(), false);
  
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      if (!vis[i][j])
        floodfill(i, j);
  
  return ans;
}

int main()
{
  cin >> N;

  char c;
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      cin >> c;
      if (c == 'R')
        grid[i][j] = 1;
      else
        grid[i][j] = 0;
    }

    cin >> grid[i][N];
  }

  for (int j = 0; j < N; ++j)
    cin >> grid[N][j];
  
  cout << floodfill() << '\n';

  int Q;
  cin >> Q;

  int a, b;
  for (int i = 0; i < Q; ++i)
  {
    cin >> a >> b;
    --a, --b;
    grid[a][b] = grid[a][b] == 0 ? 1 : 0;
    cout << floodfill() << '\n';
  }

  return 0;
}