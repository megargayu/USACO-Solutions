// https://codeforces.com/problemset/problem/1552/F

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 2e5
#define MOD 998244353
#define ll long long

int n;
vector<ll> x(MAX_N), y(MAX_N);
vector<bool> open(MAX_N);

vector<ll> dp(MAX_N), ps(MAX_N + 1, 0);

int binSearch(int loc)
{
  // bin search on closest portal opening TO THE RIGHT
  static int lo, hi, mid, ans;
  lo = 0, hi = n - 1, ans = -1;
  while (lo <= hi)
  {
    mid = lo + (hi - lo) / 2;
    if (x[mid] > loc)
    {
      ans = mid;
      hi = mid - 1;
    } else lo = mid + 1;
  }

  if (ans == -1) throw "binary search fail :(";

  return ans;
}

int main()
{
  cin >> n;

  bool tmp;
  for (int i = 0; i < n; ++i)
    cin >> x[i] >> y[i] >> tmp, open[i] = tmp;

  for (int i = 0; i < n; ++i)
  {
    dp[i] = x[i] - y[i] + ps[i] - ps[binSearch(y[i])];
    dp[i] %= MOD;
    ps[i + 1] = ps[i] + dp[i];
    ps[i + 1] %= MOD;
  }

  int ans = (x[n - 1] + 1) % MOD;
  for (int i = 0; i < n; ++i) 
    if (open[i])
      ans = (ans + dp[i]) % MOD;
  
  if (ans < 0) ans += MOD;
  cout << (ans % MOD) << '\n';

  return 0;
}