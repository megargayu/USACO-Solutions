// https://cses.fi/problemset/task/1161

#include <bits/stdc++.h>
using namespace std;

#define ll long long

priority_queue<ll, vector<ll>, greater<ll>> q;

int main()
{
  int x, n;
  cin >> x >> n;

  ll di;
  for (int i = 0; i < n; ++i)
    cin >> di, q.push(di);
  
  ll ans = 0;
  while (q.size() > 1)
  {
    const ll a = q.top(); q.pop();
    const ll b = q.top(); q.pop();
    ans += a + b;
    q.push(a + b);
  }

  cout << ans << '\n';

  return 0;
}