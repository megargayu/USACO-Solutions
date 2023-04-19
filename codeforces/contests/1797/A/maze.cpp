#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n, m;
  cin >> n >> m;

  int r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;

  int p1 = (r1 > 1) + (c1 > 1) + (r1 < n) + (c1 < m);
  int p2 = (r2 > 1) + (c2 > 1) + (r2 < n) + (c2 < m);

  cout << min(p1, p2) << '\n';
}

int main()
{
  int T;
  cin >> T;

  while (T--)
    solve();

  return 0;
}
