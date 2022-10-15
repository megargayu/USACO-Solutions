// https://cses.fi/problemset/task/1619

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 2e5

vector<pair<int, bool>> poi(MAX_N * 2);

int main()
{
  int N;
  cin >> N;

  int a, b;
  for (int i = 0; i < N; ++i)
  {
    cin >> a >> b;
    poi[i * 2] = {a, true};
    poi[i * 2 + 1] = {b, false};
  }

  sort(poi.begin(), poi.begin() + N * 2, [](const auto &a, const auto &b)
  { return a.first < b.first; });

  int ans = 0, curr = 0;
  for (int i = 0; i < N * 2; ++i)
  {
    curr += poi[i].second ? 1 : -1;
    ans = max(ans, curr);
  }

  cout << ans << '\n';

  return 0;
}
