#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1e5
#define ll long long
#define INF 2000000000LL

map<int, int> slopes;

int main()
{
  freopen("teleport.in", "r", stdin);
  freopen("teleport.out", "w", stdout);

  int N;
  cin >> N;

  ll currVal = 0, currSlope = 0, currY = -INF;

  int a, b;
  for (int i = 0; i < N; ++i)
  {
    cin >> a >> b;
    currVal += abs(a - b);

    // if b is closer to 0 than a, then NEVER use the teleporter
    if (abs(a) >= abs(a - b)) continue;
    slopes[b] += 2;

    // case (1), we want a teleporter between 0...2b
    if ((a < 0 && b > a) || (a >= 0 && b <= a))
      --slopes[0], --slopes[2*b];
    
    // case (2), we want a teleporter between 2a...2b-2a
    if ((0 <= a && a < b) || (b <= a && a < 0))
      --slopes[2*a], --slopes[2*b - 2*a];
  }

  ll ans = currVal;
  for (const auto &poi : slopes)
  {
    const int y = poi.first, ds = poi.second;
    currVal += currSlope * (y - currY);
    currY = y;
    currSlope += ds;
    ans = min(ans, currVal);
  }

  cout << ans << '\n';


  return 0;
}
