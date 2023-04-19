#include <bits/stdc++.h>
using namespace std;

int type1(int r, int c)
{
  cout << "? " << r + 1 << ' ' << c + 1 << endl;

  int result;
  cin >> result;

  return result;
}

void answer(int r, int c)
{
  cout << "! " << r + 1 << ' ' << c + 1 << endl;
}

void solve()
{
  int n, m;
  cin >> n >> m;

  int dist1 = type1(0, 0);
  int dist2 = type1(min(dist1, n - 1), min(dist1, m - 1));

  pair<int, int> p1 = {min(dist1, n - 1), min(dist1, m - 1) - dist2}, 
                 p2 = {min(dist1, n - 1) - dist2, min(dist1, m - 1)};

  bool isP1 = type1(p1.first, p1.second) == 0;
  const auto point = p1.first <= n && p1.second <= m && isP1 ? p1 : p2;

  answer(point.first, point.second);
}

int main()
{
  int T;
  cin >> T;

  while (T--)
    solve();

  return 0;
}
