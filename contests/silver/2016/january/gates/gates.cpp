#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000
#define GRID_SIZE 2005
#define f first
#define s second

vector<vector<bool>> grid(GRID_SIZE, vector<bool>(GRID_SIZE));
const vector<int> dx{-1, 1, 0, 0},
                  dy{0, 0, -1, 1};

int N;

bool inGrid(int x, int y)
{
  return 0 <= x && x < GRID_SIZE && 0 <= y && y < GRID_SIZE;
}

void floodfill(int x, int y)
{
  queue<pair<int, int>> q;
  grid[x][y] = true;
  q.push({ x, y });
  while (!q.empty())
  {
    pair<int, int> cur = q.front(); q.pop();

    for (int i = 0; i < 4; ++i)
    {
      int ax = cur.f + dx[i], ay = cur.s + dy[i];
      if (inGrid(ax, ay) && !grid[ax][ay])
      {
        grid[ax][ay] = true;
        q.push({ ax, ay });
      }
    }
  }
}

int main()
{
  ifstream fin("gates.in");
  ofstream fout("gates.out");

  fin >> N;

  char c;
  int cx = GRID_SIZE / 2, cy = GRID_SIZE / 2;
  for (int i = 0; i < N; ++i)
  {
    fin >> c;
    int ay = (c == 'N') - (c == 'S'), ax = (c == 'E') - (c == 'W');
    grid[cx += ax][cy += ay] = true;
    grid[cx += ax][cy += ay] = true;
  }

  int regions = 0;
  for (int i = 0; i < GRID_SIZE; ++i)
    for (int j = 0; j < GRID_SIZE; ++j)
      if (!grid[i][j])
      {
        floodfill(i, j);
        ++regions;
      }

  fout << regions - 1 << '\n';

  return 0;
}
