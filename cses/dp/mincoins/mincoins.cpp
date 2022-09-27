// https://cses.fi/problemset/task/1634

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100 
#define MAX_X 1e6
#define INF 1e9

vector<int> coins(MAX_N), dp(MAX_X + 1, INF);
int main()
{
  int n, x;
  cin >> n >> x;

  for (int i = 0; i < n; ++i)
    cin >> coins[i];

  dp[0] = 0;
  for (int i = 1; i <= x; ++i)
    for (int c = 0; c < n; ++c)
      if (i - coins[c] >= 0)
        dp[i] = min(dp[i], dp[i - coins[c]] + 1);

  cout << (dp[x] == INF ? -1 : dp[x]) << '\n';

  return 0;
}