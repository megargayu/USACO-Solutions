#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1e5

struct Point
{
  int x, y;
};

vector<Point> peaks(MAX_N);
vector<bool> canSee(MAX_N, true);
map<int, int> seen;

int main()
{
  ifstream fin("mountains.in");
  ofstream fout("mountains.out");

  int N;
  fin >> N;

  for (int i = 0; i < N; ++i)
    fin >> peaks[i].x >> peaks[i].y;
  
  sort(peaks.begin(), peaks.begin() + N, [](const Point &a, const Point &b)
  { return a.y == b.y ? a.x < b.x : a.y > b.y; });

  // for mountain i to be obscured, for a mountain j, the following must hold true:
  // xj - (yj - yi) <= xi <= xj + (yj - yi)
  // xj - yj + yi <= xi <= xj + yj - yi
  // xj - yj <= xi - yi <= xj + yj - 2*yi

  // this means we only need to calculate xj - yj for each peak and for each 
  // i, find the the rightmost value of xj - yj that is to the left of xi - yi,
  // and then figure out if that peak ends before or after our point (as that
  // peak is the only possible one for this to be under) 

  int lastI = 0, currY = -1;
  int ans = N;
  for (int i = 0; i < N; ++i)
  {
    if (currY != peaks[i].y)
    {
      currY = peaks[i].y;
      for (int j = lastI; j < i; ++j)
        if (canSee[j])
          seen[peaks[j].x - peaks[j].y] = j;
      lastI = i;
    }

    const int val = peaks[i].x - peaks[i].y;
    auto found = seen.upper_bound(val);
    if (found != seen.begin())
    {
      --found;
      const Point &mt = peaks[found->second];
      if (found->first <= val && val <= mt.x + mt.y - 2 * peaks[i].y)
      {
        canSee[i] = false;
        --ans;
      }
    }
  }

  fout << ans << '\n';

  return 0;
}
