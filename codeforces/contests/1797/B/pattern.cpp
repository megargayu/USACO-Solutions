#include <bits/stdc++.h>
using namespace std;

pair<int, int> get_rotated_pt(int n, int r, int c)
{
  return {n - r - 1, n - c - 1};
}

void solve()
{
  int n, k;
  cin >> n >> k;

  vector<vector<int>> grid(n, vector<int>(n));

  for (int r = 0; r < n; ++r)
    for (int c = 0; c < n; ++c)
      cin >> grid[r][c];

  int operations = 0;
  for (int r = 0; r < n; ++r)
    for (int c = 0; c < n; ++c)
    {
      if (grid[r][c] == -1) continue;

      auto [nr, nc] = get_rotated_pt(n, r, c);

      if (grid[nr][nc] != grid[r][c])
      {
        // cout << r << ' ' << c << ' ' << nr << ' ' << nc << '\n';
        ++operations;
      }
      
      grid[r][c] = -1;
      grid[nr][nc] = -1;
    }

  
  // cout << operations << '\n';
  cout << (((n % 2 == 1 || operations % 2 == k % 2) && operations <= k) ? "YES\n" : "NO\n");
}

int main()
{
  int T;
  cin >> T;

  while (T--)
    solve();

  return 0;
}
