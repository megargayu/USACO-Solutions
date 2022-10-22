#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1e5

struct Point
{
  int x, y;
};

vector<bool> canSee(MAX_N, true);
vector<Point> peaks(MAX_N);

int main()
{
  ifstream fin("mountains.in");
  ofstream fout("mountains.out");

  int N;
  cin >> N;

  for (int i = 0; i < N; ++i)
    cin >> peaks[i].x >> peaks[i].y;
  

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
    {
      if (i == j) continue;

      // check if mountain i is obstructed by mountain j
      // xj - (yj - yi) <= xi <= xj + (yj - yi)

      const int xj = peaks[j].x, yj = peaks[j].y, xi = peaks[i].x, yi = peaks[i].y;
      const bool obstructed = xj - (yj - yi) <= xi && xi <= xj + (yj - yi);
      if (obstructed)
        canSee[i] = false;
    }
  
  cout << count(canSee.begin(), canSee.begin() + N, true) << '\n';

  return 0;
}