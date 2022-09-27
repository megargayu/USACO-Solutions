// https://cses.fi/problemset/task/1635

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100
#define MAX_X 1e6
#define MOD static_cast<int>(1e9) + 7

vector<int> coins(MAX_N), dp(MAX_X + 1, 0);
int main()
{
  int n, x;
  cin >> n >> x;

  dp[0] = 0;
  for (int i = 0; i < n; ++i)
  {
    cin >> coins[i];
    dp[coins[i]] = 1;
  }
  
  for (int i = 1; i <= x; ++i)
    for (int c = 0; c < n; ++c)
      if (i - coins[c] >= 0)
      {
        dp[i] += dp[i - coins[c]];
        dp[i] %= MOD;
      }

  cout << dp[x] << '\n';

  return 0;
}