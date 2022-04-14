#include <bits/stdc++.h>
using namespace std;
// http://www.usaco.org/index.php?page=viewproblem2&cpid=645

#define MAX_N 50000
#define INF 1000000005
#define ll long long

struct Coord
{
  int x, y;
};

struct Rect
{
  Coord bl, tr;

  ll area()
  {
    return static_cast<ll>(tr.x - bl.x) * static_cast<ll>(tr.y - bl.y);
  }
};

vector<Coord> cows(MAX_N);
int N;

ll solve()
{
  Rect right{{INF, INF}, {0, 0}};

  for (int i = 0; i < N; ++i)
  {
    right.bl.x = min(right.bl.x, cows[i].x);
    right.bl.y = min(right.bl.y, cows[i].y);
    right.tr.x = max(right.tr.x, cows[i].x);
    right.tr.y = max(right.tr.y, cows[i].y);
  }

  sort(cows.begin(), cows.begin() + N, [](const Coord &a, const Coord &b)
  {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
  });

  vector<int> minfs(N), maxfs(N);
  minfs[0] = cows[0].y, maxfs[0] = cows[0].y;
  for (int i = 1; i < N; ++i) 
  {
    minfs[i] = min(minfs[i - 1], cows[i].y);
    maxfs[i] = max(maxfs[i - 1], cows[i].y);
  }

  vector<int> minte(N), maxte(N);
  minte[N - 1] = cows[N - 1].y, maxte[N - 1] = cows[N - 1].y;
  for (int i = N - 2; i >= 0; --i)
  {
    minte[i] = min(minte[i + 1], cows[i].y);
    maxte[i] = max(maxte[i + 1], cows[i].y);
  }

  Rect left{*cows.begin(), *cows.begin()};
  ll oneEnclosureArea = right.area();
  ll ans = oneEnclosureArea;

  int i;
  for (i = 0; i < N && cows[i].x == left.tr.x; ++i);

  for (; i < N; ++i)
  {
    // everything on left is part of left rect, everything on right
    // (INCLUDING EVERYTHING ON THIS LINE) is part of right rect

    // last point was in the old x value
    left.tr.x = cows[i - 1].x;
    right.bl.x = cows[i].x;

    // fix y values
    left.bl.y = minfs[i - 1];
    left.tr.y = maxfs[i - 1];

    right.bl.y = minte[i];
    right.tr.y = maxte[i];

    ans = min(ans, left.area() + right.area());

    // find last dot with same x coord
    int j;
    for (j = i; j < N && cows[j].x == cows[i].x; ++j);
    i = j - 1; // last point with same x coord, ++i will go to next x-coord
  }

  return oneEnclosureArea - ans;
}

int main()
{
  ifstream fin("split.in");
  ofstream fout("split.out");

  fin >> N;
  
  for (int i = 0; i < N; ++i)
    fin >> cows[i].x >> cows[i].y;

  ll leftRight = solve();

  // flip x and y to re-use solve function
  for (int i = 0; i < N; ++i)
    swap(cows[i].x, cows[i].y);
  
  ll topDown = solve();

  fout << max(leftRight, topDown) << '\n';

  return 0;
}
