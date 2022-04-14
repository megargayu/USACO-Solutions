#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

#define MAX_N 100

array<int, MAX_N> cows, cowsSorted;
int main()
{
  ofstream fout("outofplace.out");
  ifstream fin("outofplace.in");

  int N;
  fin >> N;

  for (int i = 0; i < N; ++i)
  {
    fin >> cows[i];
    cowsSorted[i] = cows[i];
  }

  sort(cowsSorted.begin(), cowsSorted.begin() + N);

  int count = -1;
  for (int i = 0; i < N; ++i)
    if (cows[i] != cowsSorted[i])
      ++count;

  fout << count << '\n';

  return 0;
}
