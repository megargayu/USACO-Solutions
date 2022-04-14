#include <bits/stdc++.h>
using namespace std;

#define MAX_N 50

array<array<bool, MAX_N>, MAX_N> grid;
int N, K, ans;

bool checkRow(int row, int start)
{
  for (; start < N; ++start)
    if (!grid[row][start])
      return false;
  return true;
}

bool checkCol(int start, int col)
{
  for (; start < N; ++start)
    if (!grid[start][col])
      return false;
  return true;
}

void dfs(int row, int col, bool right, int numChanged)
{
  if (row == N - 1 && col == N - 1)
  {
    ++ans;
    return;
  }

  // pruning: if 0 moves are left, check if it is possible to reach the end,
  // and exit the dfs loop
  if (numChanged == K)
  {
    if ((right && row == N - 1 && checkRow(row, col)) ||
        (!right && col == N - 1 && checkCol(row, col)))
      { ++ans; }

    return;
  }

  const auto go = [row, col](bool right, int numChanged)
  {
    int nRow = right ? row : row + 1, nCol = right ? col + 1 : col;
    if (nRow < N && nCol < N && grid[nRow][nCol])
      dfs(nRow, nCol, right, numChanged);
  };

  if ((row > 0 || col > 0) && numChanged < K) 
  {
    // pruning: if 1 turn is left, do not turn! this can be further optimized
    // to check if it can reach the end and just return from the dfs, but that
    // is not needed for all test cases.
    if (numChanged + 1 == K)
    {
      if (right && col < N - 1) goto out;
      else if (!right && row < N - 1) goto out;
    }

    go(!right, numChanged + 1);
  }

  out:
  go(right, numChanged);
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int T;
  cin >> T;
  
  for (int i = 0; i < T; ++i)
  {
    cin >> N >> K;  
    char c;

    for (int row = 0; row < MAX_N; ++row)
      for (int col = 0; col < MAX_N; ++col)
      {
        if (row < N && col < N)
        {
          cin >> c;
          grid[row][col] = (c == '.');
        } else grid[row][col] = false;
      }

    ans = 0;

    dfs(0, 0, true, 0);
    dfs(0, 0, false, 0);
    
    cout << ans << '\n';
  }
  cout.flush();

  return 0;
}
