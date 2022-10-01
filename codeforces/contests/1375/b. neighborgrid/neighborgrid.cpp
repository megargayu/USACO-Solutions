#include <bits/stdc++.h>
using namespace std;

#define MAX 300

vector<vector<int>> grid(MAX, vector<int>(MAX));
int main()
{
  int T;
  cin >> T;

  int N, M;
  for (int t = 0; t < T; ++t)
  {
    cin >> N >> M;

    for (int row = 0; row < N; ++row)
      for (int col = 0; col < M; ++col)
        cin >> grid[row][col];

    // corners
    bool possible = true;
    if (!(grid[0][0] <= 2 && grid[0][M - 1] <= 2 && grid[N - 1][0] <= 2 &&
        grid[N - 1][M - 1] <= 2)) possible = false;

    // top and bottom rows
    for (int col = 1; col < M - 1; ++col)
      if (!(grid[0][col] <= 3 && grid[N - 1][col] <= 3))
        possible = false;
    
    // left and right cols
    for (int row = 1; row < N - 1; ++row)
      if (!(grid[row][0] <= 3 && grid[row][M - 1] <= 3))
        possible = false;

    // center
    for (int row = 1; row < N - 1; ++row)
      for (int col = 1; col < M - 1; ++col)
        if (grid[row][col] > 4)
          possible = false;
    
    if (!possible)
    {
      cout << "NO\n";
      continue;
    }

    // generate grid
    grid[0][0] = 2, grid[N - 1][0] = 2, grid[0][M - 1] = 2, grid[N - 1][M - 1] = 2;
    
    for (int col = 1; col < M - 1; ++col)
      grid[0][col] = 3, grid[N - 1][col] = 3;
    
    for (int row = 1; row < N - 1; ++row)
      grid[row][0] = 3, grid[row][M - 1] = 3;
    
    for (int row = 1; row < N - 1; ++row)
      for (int col = 1; col < M - 1; ++col)
        grid[row][col] = 4;
    
    cout << "YES\n";
    for (int row = 0; row < N; ++row)
      for (int col = 0; col < M; ++col)
      {
        cout << grid[row][col];
        if (col < M - 1) cout << ' ';
        else cout << '\n';
      }
  }

  return 0;
}