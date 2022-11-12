// https://codeforces.com/contest/1744/problem/E1

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll a, b, c, d;

void solve()
{
  for (ll x = a + 1; x <= c; ++x)
  {
    const ll mult = (a * b) / gcd(a * b, x);
    const ll y = (d / mult) * mult;
    if (b < y)
    {
      cout << x << ' ' << y << '\n';
      return;
    }
  }

  cout << "-1 -1\n";
}

int main()
{
  int t;
  cin >> t;

  for (int test = 0; test < t; ++test)
  {
    cin >> a >> b >> c >> d;
    solve();
  }

  return 0;
}