// https://open.kattis.com/problems/rollercoasterfun
// TODO: https://forum.usaco.guide/t/roller-coaster-fun-kattis-knapsack-dp/3055

// TODO: 
// a) multiple solutions for each time might be better in the long run
// b) waste time doing nothing but then save it for later to get a maximum
//    fun for this time?

/*
4
8 9 8
4 6 4
6 10 6
2 6 1
1
18

should result in 16, not 18
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100
#define MAX_T 25000

vector<int> a(MAX_N), b(MAX_N), t(MAX_N);

vector<int> dp(MAX_T + 1);
vector<vector<int>> k(MAX_T + 1, vector<int>(MAX_N));

int f(int time, int i)
{
  return max(0, a[i] - k[time][i] * k[time][i] * b[i]);
}

int main()
{
  int N;
  cin >> N;

  for (int i = 0; i < N; ++i)
    cin >> a[i] >> b[i] >> t[i];

  dp[0] = 0;
  fill(k[0].begin(), k[0].end(), 0);

  for (int time = 1; time <= MAX_T; ++time)
  {
    dp[time] = dp[time - 1];
    k[time] = k[time - 1];
    for (int i = 0; i < N; ++i)
    {
      if (time - t[i] >= 0)
      {
        int newFun = dp[time - t[i]] + f(time - t[i], i);
        if (newFun > dp[time])
        {
          dp[time] = newFun;

          k[time] = k[time - t[i]];
          ++k[time][i]; // go on this ride one more time
        }
        // TODO: if newFun == dp[time], set minimum for all rides
      }
    }

    // cout << time << ' ' << dp[time] << '\n';
  }

  int Q;
  cin >> Q;

  int q;
  for (int i = 0; i < Q; ++i)
  {
    cin >> q;
    cout << dp[q] << '\n';
  }

  return 0;
}
