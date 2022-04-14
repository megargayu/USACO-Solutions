// Rectangular Pasture with 2D prefix sums!!

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 2501
#define ll long long
#define sc static_cast
#define pii pair<int, int>

vector<pii> pairs(MAX_N);
vector<vector<int>> ps(MAX_N, vector<int>(MAX_N));
int getCows(int x1, int y1, int x2, int y2)
{
  return ps[x2][y2] 
         - ps[x1-1][y2]
         - ps[x2][y1-1]
         + ps[x1-1][y1-1];
}

int main()
{
  int N;
  cin >> N;

  for (int i = 0; i < N; ++i)
    cin >> pairs[i].first >> pairs[i].second;
  
  // coordinate compression
  sort(pairs.begin(), pairs.begin() + N); 
  for (int i = 0; i < N; ++i) pairs[i].first = i + 1;

  sort(pairs.begin(), pairs.begin() + N, [](const pii &a, const pii &b)
  { return a.second < b.second; }); 
  for (int i = 0; i < N; ++i) pairs[i].second = i + 1;

  // psums
  for (int i = 0; i < N; ++i) ps[pairs[i].first][pairs[i].second] = 1;

  for (int x = 1; x <= N; ++x)
    for (int y = 1; y <= N; ++y)
    {
      ps[x][y] = ps[x][y]
                 + ps[x - 1][y]
                 + ps[x][y - 1]
                 - ps[x - 1][y - 1];
    }

  ll ans = N + 1;
  for (int i = 0; i < N; ++i)
    for (int j = i + 1; j < N; ++j)
    {
      int left = min(pairs[i].first, pairs[j].first),
          right = max(pairs[i].first, pairs[j].first),
          down = min(pairs[i].second, pairs[j].second),
          up = max(pairs[i].second, pairs[j].second);

      ll x = getCows(left, 1, right, down - 1), y = getCows(left, up + 1, right, N);
      ans += x + y + x * y + 1;
    }
  
  cout << ans << '\n';
}
