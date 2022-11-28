// https://codeforces.com/contest/782/problem/B

#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define INF 2e18L
#define MAX_N 60000
#define step 1e-7L

int n;
vector<int> x(MAX_N), v(MAX_N);

bool works(ld t)
{
  ld left = -INF, right = INF;
  for (int i = 0; i < n; ++i)
  {
    const ld currL = x[i] - t * v[i];
    const ld currR = x[i] + t * v[i];

    left = max(left, currL);
    right = min(right, currR);
  }

  return left <= right;
}

int main()
{
  cin >> n;

  for (int i = 0; i < n; ++i)
    cin >> x[i];

  for (int i = 0; i < n; ++i)
    cin >> v[i];

  ld lo = 0, hi = INF, mid, ans;
  while (lo <= hi)
  {
    mid = lo + (hi - lo) / 2;
    if (works(mid))
    {
      ans = mid;
      hi = mid - step;
    }
    else
      lo = mid + step;
  }

  cout << setprecision(12) << ans << '\n';

  return 0;
}
