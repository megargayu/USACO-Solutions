#include <bits/stdc++.h>
using namespace std;

#define MAX_N 5000000
#define ll long long

vector<ll> num_factors(MAX_N + 1);
vector<ll> ps(MAX_N + 1);

ll get_one_factor(ll n)
{
  if (n % 2 == 0)
    return 2;

  for (ll i = 3; i * i <= n; i += 2)
    if (n % i == 0)
      return i;

  return n;
}

void precompute()
{
  num_factors[0] = 0;
  num_factors[1] = 0;

  for (ll i = 2; i <= MAX_N; ++i)  
  {
    ll one_factor = get_one_factor(i);
    num_factors[i] = 1 + num_factors[i / one_factor];
  }

  ps[0] = num_factors[0];
  for (ll i = 1; i <= MAX_N; ++i)
    ps[i] = ps[i - 1] + num_factors[i];
}

void solve()
{
  ll a, b;
  cin >> a >> b;
  cout << ps[a] - ps[b] << '\n';
}

int main()
{
  precompute();
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}
