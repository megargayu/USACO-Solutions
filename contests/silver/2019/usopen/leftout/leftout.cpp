#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000

array<array<bool, MAX_N>, MAX_N> herd;

int main()
{
  ifstream fin("leftout.in");
  ofstream fout("leftout.out");

  int N;
  fin >> N;
  char c;
  for (int row = 0; row < N; ++row)
    for (int col = 0; col < N; ++col)
    {
      fin >> c;
      herd[row][col] = (c == 'L');
    }

  // flip cols
  for (int col = 0; col < N; ++col)
    if (!herd[0][col])
      for (int row = 0; row < N; ++row) // flip column
        herd[row][col] = !herd[row][col];

  // flip rows
  for (int row = 0; row < N; ++row)
    if (!herd[row][0])
      for (int col = 0; col < N; ++col) // flip row
        herd[row][col] = !herd[row][col];

  // check if all are wrong
  if (!herd[1][1] && !herd[2][1] && !herd[1][2])
  {
    fout << "1 1\n";
    return 0;
  }

  // check each row, and if only a single cow in that row is wrong
  for (int row = 1; row < N; ++row)
  {
    // if both second and third item in the row is wrong, the whole thing is
    // guaranteed to be wrong.
    if (!herd[row][1] && !herd[row][2])
    {
      fout << (row + 1) << " 1\n";
      return 0;
    }
  }

  // check each col
  for (int col = 1; col < N; ++col)
  {
    // if both second and third item in the col is wrong, the whole thing is
    // guaranteed to be wrong.
    if (!herd[1][col] && !herd[2][col])
    {
      fout << "1 " << (col + 1) << '\n';
      return 0;
    }
  }

  // check for single cow - if multiple cows left over, there is no solution!
  int rowF = -1, colF = -1;
  for (int row = 1; row < N; ++row)
  {
    for (int col = 1; col < N; ++col)
    {
      if (!herd[row][col])
      {
        if (rowF != -1)
        {
          fout << "-1\n";
          return 0;
        }
        rowF = row, colF = col;
      }
    }
  }

  if (rowF != -1) fout << (rowF + 1) << ' ' << (colF + 1) << '\n';
  else fout << "-1\n";
  return 0;
}
