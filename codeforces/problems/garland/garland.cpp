// https://codeforces.com/problemset/problem/814/C

#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int solve(int m, char c)
{
  int i = 0, j = 0;
  int ans = 0;

  int currWork = s[0] != c;
  while (i < n && j < n)
  {
    ans = max(ans, j - i + 1);

    if (currWork == m && (j == n - 1 || s[j + 1] != c))
    {
      currWork -= s[i] != c;
      ++i;
    }
    else
    {
      ++j;
      currWork += s[j] != c;
    }
  }

  return ans;
}

int main()
{
  cin >> n;
  cin >> s;

  int q;
  cin >> q;

  int m;
  char c;
  for (int i = 0; i < q; ++i)
  {
    cin >> m >> c;
    cout << solve(m, c) << '\n';
  }

  return 0;
}
