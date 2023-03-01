/*
ID: megarga1
TASK: barn1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ofstream fout("barn1.out");
  ifstream fin("barn1.in");

  int M, S, C;
  fin >> M >> S >> C;

  vector<int> stalls(C);
  for (int i{0}; i < C; ++i)
    fin >> stalls[i];

  sort(stalls.begin(), stalls.end());

  vector<pair<int, int>> spaces(C - 1);
  for (int i{1}; i < C; ++i)
    spaces[i - 1] = {i - 1, stalls[i] - stalls[i - 1]};

  sort(spaces.begin(), spaces.end(), [](auto &a, auto &b)
       { return a.second > b.second; });

  sort(spaces.begin(), M > C ? spaces.end() : spaces.begin() + (M - 1), [](auto &a, auto &b)
       { return a.first < b.first; });

  int lastI{0};
  int blocked{0};
  for (int i{0}; i < min(C - 1, M - 1); ++i)
  {
    blocked += stalls[spaces[i].first] - stalls[lastI] + 1;
    lastI = spaces[i].first + 1;
  }

  blocked += stalls[C - 1] - stalls[lastI] + 1;

  fout << blocked << '\n';

  return 0;
}
