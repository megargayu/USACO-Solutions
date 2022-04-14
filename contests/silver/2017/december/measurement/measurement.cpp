// http://usaco.org/index.php?page=viewproblem2&cpid=763
// TODO

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 10

struct Day
{
  int day, id, change;
};

array<Day, MAX_N> days;
map<int, int, greater<int>> cows;
int main()
{
  ofstream fout("measurement.out");
  ifstream fin("measurement.in");

  int N, G;
  fin >> N >> G;

  for (int i = 0; i < N; ++i)
    fin >> days[i].day >> days[i].id >> days[i].change;

  sort(days.begin(), days.begin() + N, [](const Day &a, const Day &b)
       { return a.day < b.day; });

  cows.insert({ 1, G });
  int highestCowId, ans = 0;
  for (int i = 0; i < N; ++i)
  {
    highestCowId = cows.begin()->first;
    
    auto found = cows.find(days[i].id);
    if (found != cows.end()) cows[found->first] += days[i].change;
    else cows.insert({ days[i].id, G + days[i].change });

    if (cows.begin()->first != highestCowId || cows[cows.begin()->first] < G)
      ++ans;
  }

  fout << ans << '\n';

  return 0;
}
