#include <iostream>
#include <fstream>
#include <string>
#include <array>

using namespace std;

#define MAX_N 1000

array<array<int, MAX_N>, MAX_N> psums;

int main()
{
  ofstream fout("paintbarn.out");
  ifstream fin("paintbarn.in");

  int N, K;
  fin >> N >> K;

  int x1, y1, x2, y2;
  for (int i = 0; i < N; ++i)
  {
    fin >> x1 >> y1 >> x2 >> y2;
    for (int j = x1; j < x2; ++j)
    {
      ++psums[j][y1];
      --psums[j][y2];
    }
  }

  int ans = 0;
  for (int i = 0; i < MAX_N; ++i)
  {
    int currPaint = 0;
    for (int j = 0; j < MAX_N; ++j)
    {
      currPaint += psums[i][j];
      if (currPaint == K)
        ++ans;
    }
  }

  fout << ans << '\n';

  return 0;
}
