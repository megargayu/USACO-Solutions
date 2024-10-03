// https://leetcode.com/problems/wildcard-matching/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isMatch(string s, string p)
  {
    vector<vector<bool>> dp(2004, vector<bool>(2004));

    // dp[x][y] means we haven't consumed si=0, pi=0
    dp[0][0] = true;

    for (int si = 0; si <= s.length(); si++)
      for (int pi = 0; pi < p.length(); pi++)
      {
        if (!dp[si][pi])
          continue;

        if (p[pi] == '*')
        {
          dp[si][pi + 1] = true;     // consume 0 chars and consume wildcard
          dp[si + 1][pi + 1] = true; // consume 1 char and consume wildcard
          dp[si + 1][pi] = true;     // consume 1 char and keep wildcard
        }
        else if (p[pi] == '?')
          dp[si + 1][pi + 1] = true; // consume 1 char and ?
        else if (si < s.length() && s[si] == p[pi])
          dp[si + 1][pi + 1] = true; // consume this character
      }

    return dp[s.length()][p.length()];
  }
};
