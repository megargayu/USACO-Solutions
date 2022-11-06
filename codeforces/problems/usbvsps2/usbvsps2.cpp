#include <bits/stdc++.h>
using namespace std;

#define MAX_M 3e5
#define pis pair<int, string> 
#define ll long long

vector<pis> mice(MAX_M);

int main()
{
  int a, b, c;
  cin >> a >> b >> c;

  int m;
  cin >> m;

  for (int i = 0; i < m; ++i)
    cin >> mice[i].first >> mice[i].second;

  sort(mice.begin(), mice.begin() + m, [](const auto &a, const auto &b)
  { return a.first < b.first; });

  int ans = 0;
  ll cost = 0;
  for (int i = 0; i < m; ++i)
  {
    if (mice[i].second == "USB")
    {
      if (a != 0)
        --a, ++ans, cost += mice[i].first;
      else if (c != 0)
        --c, ++ans, cost += mice[i].first;
    } 
    else 
    {
      if (b != 0)
        --b, ++ans, cost += mice[i].first;
      else if (c != 0)
        --c, ++ans, cost += mice[i].first;
    }
  }

  cout << ans << ' ' << cost << '\n';

  return 0;
}