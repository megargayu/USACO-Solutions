// https://codeforces.com/contest/1201/problem/C

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 2e5
#define ll long long

int n, k;
vector<int> a(MAX_N);

bool works(int x)
{
  ll ops = 0;
  for (int i = (n - 1) / 2; i < n; ++i)
    ops += max(0, x - a[i]);
  return ops <= k;
}

int main()
{
  cin >> n >> k;

  for (int i = 0; i < n; ++i)
    cin >> a[i];

  sort(a.begin(), a.begin() + n);

  int lo = 1, hi = 2e9, mid, ans = 1;
  while (lo <= hi)
  {
    mid = lo + (hi - lo) / 2;
    if (works(mid))
    {
      ans = mid;
      lo = mid + 1;
    }
    else
      hi = mid - 1;
  }

  cout << ans << '\n';

  return 0;
}
