#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1e5

enum class Direction
{
  N, E, S, W
};

map<int, vector<int>> x, y;
int main()
{
  ifstream fin("lasers.in");
  ofstream fout("lasers.out");

  int N, xl, yl, xb, yb;
  fin >> N >> xl >> yl >> xb >> yb;

  x[yl].push_back(xl); y[xl].push_back(yl);
  x[yb].push_back(xb); y[xb].push_back(yb);
  int a, b;
  for (int i = 1; i <= N; ++i)
  {
    fin >> a >> b;
    x[b].push_back(a);
    y[a].push_back(b);
  }

  for (auto &val : x) sort(val.second.begin(), val.second.end());
  for (auto &val : y) sort(val.second.begin(), val.second.end());

  queue<pair<Direction, pair<int, int>>> q;
  q.push({ Direction::N, { xl, yl } });
  while (!q.empty())
  {

  }

  return 0;
}
