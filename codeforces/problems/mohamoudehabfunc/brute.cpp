#include <bits/stdc++.h>
using namespace std;

#define MAX 1e5
#define ll long long

vector<int> a(MAX), b(MAX);

int main()
{
  int n, m, q;
  cin >> n >> m >> q;

  for (int i = 0; i < n; ++i)
    cin >> a[i];

  for (int i = 0; i < m; ++i)
    cin >> b[i];

  ll ans = 2e18;
  for (int j = 0; j <= m - n; ++j)
  {
    ll sum = 0;
    int sign = 1;
    for (int i = 0; i < n; ++i)
    {
      sum += sign * (a[i] - b[i + j]);
      sign *= -1;
    }

    ans = min(ans, abs(sum));
  }

  cout << ans << '\n';

  return 0;
}