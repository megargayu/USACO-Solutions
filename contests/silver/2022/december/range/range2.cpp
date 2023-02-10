#include <bits/stdc++.h>
using namespace std;

#define MAX_N 300

#define INF 2e9

vector<vector<int>> r(MAX_N, vector<int>(MAX_N));
vector<int> ans(MAX_N);

int getr(int i, int j)
{
  assert(j >= i);
  return r[i][j - i];
}

int main()
{
  int N;
  cin >> N;

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N - i; ++j)
      cin >> r[i][j];

  ans[N - 1] = 0;
  for (int i = N - 2; i >= 0; --i)
  {
    ans[i] = ans[i + 1] + getr(i, i + 1);
    
    int cmax = -INF, cmin = INF;
    for (int j = i; j < N; ++j)
    {
      cmin = min(cmin, ans[j]);
      cmax = max(cmax, ans[j]);

      if (cmax - cmin != getr(i, j))
      {
        ans[i] = ans[i + 1] - getr(i, i + 1);
        break;
      }
    }
  }

  for (int i = 0; i < N; ++i)
  {
    cout << ans[i];
    if (i < N - 1)
      cout << ' ';
  }
  cout << '\n';

  return 0;
}