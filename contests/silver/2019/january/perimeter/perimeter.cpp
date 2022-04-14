#include <iostream>
#include <fstream>
#include <string>

#include <vector>
#include <utility>

#define MAX_N 1000

using namespace std;

const vector<int> drow{1, 0, -1, 0};
const vector<int> dcol{0, 1, 0, -1};

vector<vector<pair<bool, bool>>> grid{};
int perimeter{0}, area{0};
int N;

bool inGrid(int row, int col)
{
  return row >= 0 && row < N && col >= 0 && col < N;
}

void dfs(int row, int col)
{
  grid[row][col].second = true;
  ++area;

  for (int i{0}; i < 4; ++i)
  {
    int newRow{row + drow[i]}, newCol{col + dcol[i]};
    // not in grid or visited
    if (!inGrid(newRow, newCol)) // on edge, add perimeter
    {
      ++perimeter;
      continue;
    }

    // is outside of blob, count as perimeter (we want to double count!)
    if (!grid[newRow][newCol].first)
      ++perimeter;

    // is part of blob, make sure not visited and dfs
    else if (!grid[newRow][newCol].second)
      dfs(newRow, newCol);
  }
}

int main()
{
  ofstream fout("perimeter.out");
  ifstream fin("perimeter.in");

  grid.resize(MAX_N, vector<pair<bool, bool>>(MAX_N));

  fin >> N;
  char c;
  for (int row{0}; row < N; ++row)
    for (int col{0}; col < N; ++col)
    {
      fin >> c;
      grid[row][col] = {c == '#', false};
    }

  int maxArea{0}, maxPerimeter{0};
  for (int row{0}; row < N; ++row)
    for (int col{0}; col < N; ++col)
    {
      if (!grid[row][col].first || grid[row][col].second)
        continue;
      area = 0;
      perimeter = 0;
      dfs(row, col);

      if ((area > maxArea) || (area == maxArea && perimeter < maxPerimeter))
      {
        maxArea = area;
        maxPerimeter = perimeter;
      }
    }

  fout << maxArea << ' ' << maxPerimeter << '\n';

  return 0;
}
