// https://cses.fi/problemset/task/1164

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 2e5

struct Poi
{
  int t;
  bool isStart;
  int i;
};

vector<Poi> poi(MAX_N * 2);
priority_queue<int, vector<int>, greater<int>> rooms;
vector<int> ans(MAX_N);

int main()
{
  int n;
  cin >> n;

  for (int i = 1; i <= MAX_N; ++i)
    rooms.push(i);

  int a, b;
  for (int i = 0; i < n; ++i)
  {
    cin >> a >> b;
    poi[i * 2] = {a, true, i};
    poi[i * 2 + 1] = {b, false, i};
  }

  sort(poi.begin(), poi.begin() + n * 2, [](const Poi &a, const Poi &b)
  { if (a.t == b.t)
      return a.isStart; 
    return a.t < b.t; });

  for (int i = 0; i < n * 2; ++i)
  {
    if (poi[i].isStart)
    {
      ans[poi[i].i] = rooms.top();
      rooms.pop();
    }
    else
    {
      rooms.push(ans[poi[i].i]);
    }
  }

  cout << *max_element(ans.begin(), ans.begin() + n) << '\n';
  for (int i = 0; i < n; ++i)
    cout << ans[i] << ' ';
  cout << '\n';

  return 0;
}
