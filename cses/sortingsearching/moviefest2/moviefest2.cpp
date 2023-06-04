// https://cses.fi/problemset/task/1632

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 2e5

vector<pair<int, int>> movies(MAX_N);
multiset<int> endings;

int main()
{
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; ++i)
    cin >> movies[i].first >> movies[i].second;

  sort(movies.begin(), movies.begin() + n, [](const auto &a, const auto &b)
       { if (a.second == b.second)
      return a.first < b.first;
    return a.second < b.second; });

  for (int i = 0; i < k; ++i)
    endings.insert(0);

  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    auto it = endings.upper_bound(movies[i].first);
    if (it == endings.begin())
      continue;

    endings.erase(--it);
    endings.insert(movies[i].second);
    ++ans;
  }

  cout << ans << '\n';

  return 0;
}