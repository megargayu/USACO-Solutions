#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX_N 100
#define INF 2e18

int N;
ll tC, tM;
vector<ll> a(MAX_N), b(MAX_N), c(MAX_N);

bool check(ll w)
{
  const ll d = tC + tM - w;
  ll lo = max(1LL, d - tM), hi = min(tC, d - 1LL);
  
  for (int i = 0; i < N; ++i)
  {      

    if (a[i] > b[i])
      hi = min(hi, (c[i] - b[i] * d) / (a[i] - b[i]));
    else if (a[i] < b[i])
    {
      const ll t1 = b[i] * d - c[i], t2 = b[i] - a[i];
      lo = max(lo, t1 / t2 + (t1 % t2 != 0)); // ceil(t1 / t2)
    }
    else
    {
      if (c[i] < b[i] * d)
        return false;
    }
  }

  return lo <= hi;
}


void solve()
{
  cin >> N >> tC >> tM;
  for (int i = 0; i < N; ++i)
    cin >> a[i] >> b[i] >> c[i];

  ll lo = 0, hi = tC + tM - 2, mid, ans = tC + tM - 2;
  while (lo <= hi)
  {
    mid = lo + (hi - lo) / 2;
    if (check(mid))
    {
      ans = mid;
      hi = mid - 1;
    }
    else
      lo = mid + 1;
  }

  cout << ans << '\n';
}

int main()
{
  int T;
  cin >> T;

  while (T--)
    solve();

  return 0;
}
