#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000

vector<vector<int>> grid(MAX_N, vector<int>(MAX_N));
int main()
{
  int N;
  cin >> N;

  for (int row = 0; row < N; ++row)
    for (int col = 0; col < N; ++col)
      cin >> grid[row][col];
  
  int rowsAlternating = 0;
  for (int col = 0; col < N; ++col)
  {
    int start0 = 0, start1 = 0;
    for (int row = 0; row < N; row += 2) start0 += grid[row][col];
    for (int row = 1; row < N; row += 2) start1 += grid[row][col];
    rowsAlternating += max(start0, start1);
  }

  int colsAlternating = 0;
  for (int row = 0; row < N; ++row)
  {
    int start0 = 0, start1 = 0;
    for (int col = 0; col < N; col += 2) start0 += grid[row][col];
    for (int col = 1; col < N; col += 2) start1 += grid[row][col];
    colsAlternating += max(start0, start1);
  }

  cout << max(rowsAlternating, colsAlternating) << '\n';

  return 0;
}
