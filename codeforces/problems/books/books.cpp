// https://codeforces.com/contest/279/problem/B

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1e5

vector<int> a(MAX_N);

int main()
{
  int n, t;
  cin >> n >> t;
  
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  int i = -1, j = -1;
  int currTime = 0;
  for (int x = 0; x < n; ++x)
  {
    if (a[x] <= t)
    {
      i = j = x;
      currTime = a[x];
      break;
    }
  }

  if (i == -1)
  {
    cout << "0\n";
    return 0;
  }

  int ans = 0;
  while (i < n && j < n)
  {
    ans = max(ans, j - i + 1);

    if (j < n - 1 && currTime + a[j + 1] <= t)
    {
      ++j;
      currTime += a[j];
    }
    else
    {
      currTime -= a[i];
      ++i;
    }
  }

  cout << ans << '\n';

  return 0;
}
