#include <bits/stdc++.h>
using namespace std;

#define MAX_N 2e5
#define ll long long
#define pii pair<int, int>

int N, C;
// first = from anywhere, second = from 0
vector<pii> prices(MAX_N);
vector<ll> psum(MAX_N + 1);

int solve()
{
  sort(prices.begin(), prices.begin() + N);

  psum[0] = 0;
  for (int i = 0; i < N; ++i)
    psum[i + 1] = psum[i] + prices[i].first;
  
  ll ans = 0;

  for (int i = 0; i < N; ++i)
  {    
    int lo = 0, hi = N, mid;
    ll currAns = 0;
    while (lo <= hi)
    {
      mid = lo + (hi - lo) / 2;
      ll tp = mid + 1, price = psum[mid] + prices[i].second;
      if (mid > i) // we already count the "first" teleporter in our psums
        price -= prices[i].first, --tp;
        
      if (price <= C)
      {
        currAns = max(tp, currAns);
        lo = mid + 1;
      }
      else
        hi = mid - 1;
    }

    ans = max(currAns, ans);
  }

  return ans;
}

int main()
{
  int T;
  cin >> T;

  int p;
  for (int t = 0; t < T; ++t)
  {
    cin >> N >> C;
    for (int i = 0; i < N; ++i)
    {
      cin >> p;
      prices[i] = {p + min(i + 1, N - i), p + i + 1};
    }

    cout << solve() << '\n';
  }

  return 0;
}
