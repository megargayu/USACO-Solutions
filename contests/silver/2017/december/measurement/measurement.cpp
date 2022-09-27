#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

map<int, int> cows;
map<int, int, greater<int>> cowsWithVal;

struct Day
{
  int day, id, change;
};

vector<Day> days(MAX_N);

int main()
{
  ofstream fout("measurement.out");
  ifstream fin("measurement.in");

  int N, G;
  fin >> N >> G;

  for (int i = 0; i < N; ++i)
  {
    fin >> days[i].day >> days[i].id >> days[i].change;
    cows[days[i].id] = G;
  }

  cowsWithVal[G] = N + 1;

  sort(days.begin(), days.begin() + N, [](const Day &a, const Day &b)
       { return a.day < b.day; });

  int ans = 0;
  for (int i = 0; i < N; ++i)
  {
    int &milk = cows[days[i].id];

    const bool wasOnLeaderboard = milk == cowsWithVal.begin()->first;
    const int &prevCount = cowsWithVal[milk]--;
    if (prevCount == 1)
      cowsWithVal.erase(milk);

    milk += days[i].change;

    const int &newCount = ++cowsWithVal[milk];
    const bool isOnLeaderboard = milk == cowsWithVal.begin()->first;

    if ((wasOnLeaderboard && (!isOnLeaderboard || prevCount != 1 || newCount != 1)) ||
        (!wasOnLeaderboard && isOnLeaderboard))
    {
      ++ans;
    }
  }

  fout << ans << '\n';

  return 0;
}