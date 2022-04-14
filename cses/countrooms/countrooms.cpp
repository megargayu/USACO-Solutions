// https://cses.fi/problemset/task/1192/

#include <bits/stdc++.h>

#define MAX 1000

using namespace std;

array<int, 4> drow{0, 1, 0, -1};
array<int, 4> dcol{1, 0, -1, 0};
array<array<pair<bool, bool>, MAX>, MAX> grid;
int N, M;
int currComponent = 0;

bool inGrid(int row, int col)
{
  return row >= 0 && row < N && col >= 0 && col < M;
}

void dfs(int row, int col)
{
  grid[row][col].second = true;

  for (int i = 0; i < 4; ++i)
  {
    int newRow = row + drow[i], newCol = col + dcol[i];
    if (inGrid(newRow, newCol) && grid[newRow][newCol].first && !grid[newRow][newCol].second)
      dfs(newRow, newCol);
  }
}

int main()
{
  cin >> N >> M;

  char c;
  for (int row = 0; row < N; ++row)
    for (int col = 0; col < M; ++col)
    {
      cin >> c;
      grid[row][col] = {(c == '.'), false};
    }

  for (int row = 0; row < N; ++row)
    for (int col = 0; col < M; ++col)
      if (grid[row][col].first && !grid[row][col].second)
      {
        ++currComponent;
        dfs(row, col);
      }

  cout << currComponent;

  return 0;
}