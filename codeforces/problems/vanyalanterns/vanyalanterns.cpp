// https://codeforces.com/contest/492/problem/B

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000
#define ll long long

int n, l;
vector<ll> lanterns(MAX_N);

bool works(ll d)
{
  // we know that 0..lanterns[0] is lit and that lanterns[n - 1]..l is lit
  // because it is the minimum in the binsearch
  ll litSoFar = lanterns[0] + d;
  for (int i = 1; i < n; ++i)
  {
    // light from this lantern will not reach to cover everything
    // from what has already been covered to this lantern
    if (d < lanterns[i] && lanterns[i] - d > litSoFar)
      return false;

    litSoFar = lanterns[i] + d;
  }

  return true;
}

int main()
{
  cin >> n >> l;

  l *= 2;

  for (int i = 0; i < n; ++i)
    cin >> lanterns[i], lanterns[i] *= 2;

  sort(lanterns.begin(), lanterns.begin() + n);

  ll lo = max(lanterns[0], l - lanterns[n - 1]),
     hi = l + 5, mid, ans = -1;
  while (lo <= hi)
  {
    mid = lo + (hi - lo) / 2;
    if (works(mid))
    {
      ans = mid;
      hi = mid - 1;
    }
    else
      lo = mid + 1;
  }

  assert(ans != -1);

  cout << ans / 2 << '.' << (ans % 2 == 0 ? '0' : '5') << "000000000\n";

  return 0;
}
