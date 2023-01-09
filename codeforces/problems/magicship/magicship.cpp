#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX_N 1e5+10

ll px1, py1, px2, py2;
int N;
string s;

vector<ll> dx(MAX_N), dy(MAX_N);

bool works(ll x)
{
  ll px3 = px1 + dx[N] * (ll)(x / N) + dx[x % N],
     py3 = py1 + dy[N] * (ll)(x / N) + dy[x % N];

  ll need = abs(px2 - px3) + abs(py2 - py3);
  return need <= x;
}

int main()
{
  cin >> px1 >> py1 >> px2 >> py2;
  cin >> N >> s;

  for (int i = 0; i < N; ++i)
  {
    dx[i + 1] = dx[i], dy[i + 1] = dy[i];

    switch (s[i])
    {
      case 'U': ++dy[i + 1]; break;
      case 'D': --dy[i + 1]; break;
      case 'L': --dx[i + 1]; break;
      case 'R': ++dx[i + 1]; break;
    }
  }

  ll lo = 0, hi = 2e18, mid, ans = -1;
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

  cout << ans << '\n';

  return 0;
}
