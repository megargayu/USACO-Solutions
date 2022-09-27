#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

struct Point
{
  int x, y;
};

struct MirrorIndex
{
  int i, j;
  bool horiz;
};

// TODO

vector<Point> poi(MAX_N + 1);
map<int, vector<int>> xM, yM;
int N;
Point laser, barn;
int main()
{
  ifstream fin("lasers.in");
  ofstream fout("lasers.out");

  fin >> N >> laser.x >> laser.y >> barn.x >> barn.y;
  int left, right, up, down;
  for (int i = 0; i < N; ++i)
  {
    fin >> poi[i].x >> poi[i].y;
    xM[poi[i].x].push_back(poi[i].y);
    yM[poi[i].y].push_back(poi[i].x);
  }

  poi[N] = barn;

  for (auto &[x, yArr] : xM) sort(yArr.begin(), yArr.end());
  for (auto &[y, xArr] : yM) sort(xArr.begin(), xArr.end());

  queue<MirrorIndex> q;

  while (!q.empty())
  {
    
  }

  return 0;
}