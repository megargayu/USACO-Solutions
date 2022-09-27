// https://cses.fi/problemset/task/1629

#include <iostream>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

#define MAX_N 200000

array<pair<int, int>, MAX_N> movies;

int main()
{
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i)
    cin >> movies[i].first >> movies[i].second;

  sort(movies.begin(), movies.begin() + n,
       [](const pair<int, int> &a, const pair<int, int> &b)
       { return a.second < b.second; });

  int ans = 0, lastEnd = 0;
  for (auto movie : movies)
    if (movie.first >= lastEnd)
    {
      lastEnd = movie.second;
      ++ans;
    }

  cout << ans;

  return 0;
}
