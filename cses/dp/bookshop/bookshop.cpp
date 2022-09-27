// https://cses.fi/problemset/task/1158

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000
#define MAX_X 100000

vector<int> price(MAX_N), pages(MAX_N);
vector<vector<int>> dp(MAX_N + 1, vector<int>(MAX_X + 1, 0));
int main()
{
  int n, x;
  cin >> n >> x;

  for (int i = 0; i < n; ++i)
    cin >> price[i];

  for (int i = 0; i < n; ++i)
    cin >> pages[i];

  for (int b = 1; b <= n; ++b)
  {
    const int currPrice = price[b - 1];
    const int currPages = pages[b - 1];

    for (int p = 1; p <= x; ++p)
    {
      dp[b][p] = dp[b - 1][p];

      if (p >= price[b - 1])
        dp[b][p] = max(dp[b][p], dp[b - 1][p - currPrice] + currPages);
    }
  }

  cout << dp[n][x] << '\n';

  return 0;
}
