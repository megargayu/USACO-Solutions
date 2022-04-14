#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100

const array<int, 4> drow{-1, 1, 0, 0};
const array<int, 4> dcol{0, 0, -1, 1};

array<array<pair<bool, vector<pair<int, int>>>, MAX_N>, MAX_N> grid;
array<array<bool, MAX_N>, MAX_N> visited;
int N, M;

bool inGrid(int row, int col)
{
  return 0 <= row && row < N && 0 <= col && col < N;
}

bool canReach(int row, int col)
{
  for (int i = 0; i < 4; ++i)
  {
    int newRow = row + drow[i], newCol = col + dcol[i];
    if (inGrid(newRow, newCol) && visited[newRow][newCol])
      return true;
  }

  return false;
}

void dfs(int row, int col)
{
  visited[row][col] = true;
  for (const pair<int, int> &adj : grid[row][col].second)
  {
    if (!grid[adj.first][adj.second].first)
    {
      grid[adj.first][adj.second].first = true;
      if (canReach(adj.first, adj.second))
        dfs(adj.first, adj.second);
    }
  }

  for (int i = 0; i < 4; ++i)
  {
    int newRow = row + drow[i], newCol = col + dcol[i];
    if (inGrid(newRow, newCol) && grid[newRow][newCol].first && !visited[newRow][newCol])
      dfs(newRow, newCol);
  }
}

int main()
{
  ifstream fin("lightson.in");
  ofstream fout("lightson.out");

  fin >> N >> M;

  int x1, y1, x2, y2;
  for (int i = 0; i < M; ++i)
  {
    fin >> x1 >> y1 >> x2 >> y2;
    --x1, --y1, --x2, --y2;

    grid[x1][y1].second.push_back({x2, y2});
  }

  grid[0][0].first = true;
  dfs(0, 0);

  int result = 0;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      if (grid[i][j].first)
        ++result;

  fout << result << '\n';
}
