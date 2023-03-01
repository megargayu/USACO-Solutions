/*
ID: megarga1
TASK: milk
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
  ofstream fout("milk.out");
  ifstream fin("milk.in");

  int N, M;
  fin >> N >> M;

  vector<pair<int, int>> farmers(M);
  for (int i{0}; i < M; ++i)
  {
    pair<int, int> farmer;
    fin >> farmer.first >> farmer.second;
    farmers[i] = farmer;
  }

  sort(farmers.begin(), farmers.end(), [](pair<int, int> &a, pair<int, int> &b)
       { return a.first < b.first; });

  int farmer{0};
  int ans{0};
  while (N > 0)
  {
    int take{farmers[farmer].second};
    if (N - take < 0)
      take = N;

    ans += farmers[farmer].first * take;
    N -= take;
    ++farmer;
  }

  fout << ans << '\n';

  return 0;
}
