#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define MAX_N 100

ll N, TC, TM;
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

  ll ans = 2e18;
  for (ll tc = 1; tc <= TC; ++tc)
  {
    ll tm = solve(tc);
    if (tm == -1) break;

    ans = min(ans, TC - tc + TM - tm);
  }

  cout << ans << '\n';
}

int main()
{
  int T;
  cin >> T;

  char newline;
  while (T--)
  {
    cin.get(newline);
    assert(newline == '\n');
    solve();
  }
}