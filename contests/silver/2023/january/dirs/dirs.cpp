// doesn't work

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1500

int N;

const vector<int> dr{1, 0},
                  dc{0, 1};

struct Edge
{
  int i, j;
};

// 0 = D, 1 = R
vector<vector<int>> grid(MAX_N + 1, vector<int>(MAX_N + 1));
vector<vector<bool>> vis(MAX_N, vector<bool>(MAX_N));

vector<vector<int>> val(MAX_N + 1, vector<int>(MAX_N + 1));

int ans = 0;

int floodfill(int i, int j)
{  
  bool firstVis = !vis[i][j];
  vis[i][j] = true;

  int nr = i + dr[grid[i][j]], nc = j + dc[grid[i][j]];
  if (nr == N || nc == N) // vat
  {
    val[i][j] = grid[nr][nc];
    if (firstVis)
      ans += val[i][j];

    // cout << i << ' ' << j << ' ' << grid[nr][nc] << '\n';
    return grid[nr][nc];
  }
  else
  {
    // assert(adj[nr][nc].i == -1);
    // adj[nr][nc] = {i, j};

    val[i][j] = floodfill(nr, nc);
    if (firstVis)
      ans += val[i][j];

    // cout << i << ' ' << j << ' ' << val[i][j] << '\n';
    return val[i][j];
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

void backFloodfill(int i, int j, int nVal)
{
  ans = ans - val[i][j] + nVal;
  val[i][j] = nVal;

  // to the left was right?
  if (j > 0 && grid[i][j - 1] == 1)
    backFloodfill(i, j - 1, nVal);
  
  // above was down?
  if (i > 0 && grid[i - 1][j] == 0)
    backFloodfill(i - 1, j, nVal);
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
    val[i][N] = grid[i][N];
  }

  for (int j = 0; j < N; ++j)
  {
    cin >> grid[N][j];
    val[N][j] = grid[N][j];
  }
  
  cout << floodfill() << '\n';

  int Q;
  cin >> Q;

    int a, b;
  for (int i = 0; i < Q; ++i)
  {
    cin >> a >> b;
    --a, --b;

    grid[a][b] = grid[a][b] == 0 ? 1 : 0;

    backFloodfill(a, b, val[a + dr[grid[a][b]]][b + dc[grid[a][b]]]);

    cout << ans << '\n';
  }

  return 0;
}