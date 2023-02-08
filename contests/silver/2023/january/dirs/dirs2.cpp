// gives correct answer

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1500

int N;

// 0 = D, 1 = R
vector<vector<int>> grid(MAX_N + 1, vector<int>(MAX_N + 1)),
    dp(MAX_N + 1, vector<int>(MAX_N + 1));

int getVal()
{
  int ans = 0;

  for (int r = 0; r < N; ++r)
    if (r != N)
      ans += grid[r][N] * dp[r][N];

  for (int c = 0; c < N; ++c)
    if (c != N)
      ans += grid[N][c] * dp[N][c];

  return ans;
}

void update(int r, int c, int by)
{
  int cr = r, cc = c;
  while (cr < N && cc < N)
  {
    if (cr != r || cc != c)
      dp[cr][cc] += by;

    // cout << cr << ' ' << cc << '\n';
    
    int ncr = cr + (grid[cr][cc] == 0);
    cc += grid[cr][cc] == 1;
    cr = ncr;
  }

  dp[cr][cc] += by;
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

      dp[i][j] = 1;
    }

    cin >> grid[i][N];
  }

  for (int j = 0; j < N; ++j)
    cin >> grid[N][j];

  for (int r = 0; r < N + 1; ++r)
    for (int c = 0; c < N + 1; ++c)
    {
      if (r > 0 && c != N && grid[r - 1][c] == 0)
        dp[r][c] += dp[r - 1][c];

      if (c > 0 && r != N && grid[r][c - 1] == 1)
        dp[r][c] += dp[r][c - 1];
    }

  dp[N][N] = 0;

  cout << getVal() << '\n';

  int Q;
  cin >> Q;

  int a, b;
  for (int q = 0; q < Q; ++q)
  {
    cin >> a >> b;
    --a, --b;

    update(a, b, -dp[a][b]);
    grid[a][b] = grid[a][b] == 0 ? 1 : 0;
    update(a, b, dp[a][b]);

    cout << getVal() << '\n';
  }

  return 0;
}