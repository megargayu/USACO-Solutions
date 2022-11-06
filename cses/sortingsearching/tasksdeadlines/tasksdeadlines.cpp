// https://cses.fi/problemset/task/1630

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 2e5
#define ll long long

vector<pair<int, int>> tasks(MAX_N);
int main()
{
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i)
    cin >> tasks[i].first >> tasks[i].second;

  sort(tasks.begin(), tasks.begin() + n, [](const auto &a, const auto &b)
  { return a.first < b.first; });

  ll curr = 0, ans = 0;
  for (int i = 0; i < n; ++i){
    curr += tasks[i].first;
    ans += tasks[i].second - curr;
  }

  cout << ans << '\n';

  return 0;
}
