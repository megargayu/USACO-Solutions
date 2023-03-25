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

void solve()
{
  cin >> N >> TC >> TM;

  for (int i = 0; i < N; ++i)
    cin >> a[i] >> b[i] >> c[i];

  ll ans = 2e18;
  for (ll tc = TC; tc >= 1; --tc)
    for (ll tm = TM; tm >= 1; --tm)
    {
      if (possible(tc, tm))
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