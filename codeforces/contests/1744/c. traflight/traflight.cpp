// https://codeforces.com/contest/1744/problem/C

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 2e5

int n;
char c;
string s;

int solve()
{
  if (c == 'g')
    return 0;

  int j = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i)
  {
    if (s[i] != c) continue;
    while (i >= j || s[j % n] != 'g') ++j;
    ans = max(ans, j - i);
    //cout << i << ' ' << j << '\n';
    i = j;
  }

  return ans;
}

int main()
{
  int t;
  cin >> t;

  for (int test = 0; test < t; ++test)
  {
    cin >> n >> c;
    cin >> s;
    cout << solve() << '\n';
  }
  
  return 0;
}