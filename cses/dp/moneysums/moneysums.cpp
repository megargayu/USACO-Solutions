// https://cses.fi/problemset/task/1745

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100
#define MAX_SUM 100000

vector<int> coins(MAX_N);
vector<vector<bool>> dp(MAX_N, vector<bool>(MAX_SUM + 1, false));

int main()
{
  int n;
  cin >> n;

  dp[0][0] = true;
  for (int i = 0; i < n; ++i)
    cin >> coins[i];

  dp[0][coins[0]] = true;
  int k = n == 1;
  for (int c = 1; c < n; ++c)
    for (int i = 0; i <= MAX_SUM; ++i)
    {
      dp[c][i] = dp[c][i] || dp[c - 1][i];
      if (i >= coins[c])
        dp[c][i] = dp[c][i] || dp[c - 1][i - coins[c]];

      if (c == n - 1 && dp[c][i]) ++k;
    }
  
  if (n > 1) --k;

  cout << k << '\n';
  for (int i = 1; i <= MAX_SUM; ++i)
    if (dp[n - 1][i])
    {
      cout << i;
      if (k > 1) cout << ' ';
      --k;
    }
  
  cout << '\n';

  return 0;
}