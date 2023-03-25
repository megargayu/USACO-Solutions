#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define MAX_N 100

int N;
ll TC, TM;
vector<ll> a(MAX_N), b(MAX_N), c(MAX_N);

bool possible(ll tc, ll tm)
{
  for (int i = 0; i < N; ++i)
    if (tc * a[i] + tm * b[i] > c[i])
      return false;
  
  return true;
}

ll solve(ll tc)
{
  ll lo = 1, hi = TM, mid, ans = -1;
  while (lo <= hi)
  {
    mid = lo + (hi - lo) / 2;
    bool poss = possible(tc, mid);
    if (poss)
    {
      ans = mid;
      lo = mid + 1;
    }
    else hi = mid - 1;
  }

  return ans;
}

void solve()
{
  cin >> N >> TC >> TM;

  for (int i = 0; i < N; ++i)
    cin >> a[i] >> b[i] >> c[i];
  
  // fix `tc` with binsearch
  ll lo = 1, hi = TC, mid;
  ll bestTC = 1, bestTM = 1;
  while (lo <= hi)
  {
    mid = lo + (hi - lo) / 2;
    ll tm = solve(mid);

    // if impossible with this tc or the best
    // you can get with this tc is worse than what we already
    // have tried, then
    if (tm == -1 || mid + tm < bestTC + bestTM)
      hi = mid - 1;
    else
    {
      bestTC = mid;
      bestTM = tm;
      lo = mid + 1;
    }
  }

  cout << bestTC << ' ' << bestTM << '\n';
  ll ans = (TC - bestTC) + (TM - bestTM);
  cout << ans << '\n';
}

int main()
{
  // int T;
  // cin >> T;

  // char newline;
  // while (T--)
  // {
  //   cin.get(newline);
  //   assert(newline == '\n');
  //   solve();
  // }

  solve();

  return 0;
}