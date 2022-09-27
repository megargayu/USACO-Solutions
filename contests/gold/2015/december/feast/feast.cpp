#include <bits/stdc++.h>
using namespace std;

#define MAX_T 5e6

vector<vector<int>> dp(2, vector<int>(MAX_T + 1));
int main()
{
  ifstream fin("feast.in");
  ofstream fout("feast.out");

  int T, A, B;
  fin >> T >> A >> B;

  dp[0][0] = true;
  for (int i = 0; i <= T; ++i)
  {
    if (i >= A) dp[0][i] |= dp[0][i - A];
    if (i >= B) dp[0][i] |= dp[0][i - B];
    dp[1][i / 2] |= dp[0][i]; // drink water here
  }

  for (int i = 0; i <= T; ++i)
  {
    if (i >= A) dp[1][i] |= dp[1][i - A];
    if (i >= B) dp[1][i] |= dp[1][i - B];
  }

  for (int i = T; i >= 0; --i)
    if (dp[1][i])
    {
      fout << i << '\n';
      break;
    }

  return 0;
}