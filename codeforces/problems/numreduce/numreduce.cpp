// https://codeforces.com/problemset/problem/1765/N

#include <bits/stdc++.h>
using namespace std;



void solve()
{
  string s;
  int k;

  cin >> s >> k;

  vector<vector<int>> closest(s.size(), vector<int>(10));

  fill(closest[s.size() - 1].begin(), closest[s.size() - 1].end(), -1);
  closest[s.size() - 1][s[s.size() - 1] - '0'] = s.size() - 1;

  for (int i = s.size() - 2; i >= 0; --i)
  {
    closest[i] = closest[i + 1];
    closest[i][s[i] - '0'] = i;
  }

  int si = 0;
  int left = k;

  for (int i = 0; i < s.size() - k && si < s.size(); ++i)
    for (int j = (i == 0); j <= 9; ++j)
      if (closest[si][j] != -1 && closest[si][j] - si <= left)
      {
        cout << j;
        left -= closest[si][j] - si;
        si = closest[si][j] + 1;
        break;
      }

  cout << '\n';
}

int main()
{
  int T;
  cin >> T;

  while (T--)
    solve();

  return 0;
}
