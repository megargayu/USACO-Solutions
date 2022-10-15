// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/0000000000337b4d

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 2e5
#define ll long long

vector<int> vals(MAX_N + 1);
vector<ll> ps(MAX_N + 1), mps(MAX_N + 1);

// TODO: solve whole problem with segtrees?

int main()
{
  int T;
  cin >> T;

  int N, Q;
  int mult;

  ll ans;

  char c;
  int a, b;
  for (int t = 1; t <= T; ++t)
  {
    cin >> N >> Q;
    mult = 1;

    ps[0] = 0, mps[0] = 0;
    for (int i = 1; i <= N; ++i)
    {
      cin >> vals[i];
      ps[i] = ps[i - 1] + mult * vals[i];
      mps[i] = mps[i - 1] + mult * vals[i] * i;
      mult *= -1;
    }

    ans = 0;
    for (int q = 0; q < Q; ++q)
    {
      cin >> c >> a >> b;
      mult = a % 2 == 0 ? -1 : 1;
      if (c == 'Q')
        ans += mult * ((mps[b] - mps[a - 1]) - (a - 1) * (ps[b] - ps[a - 1]));
      else if (c == 'U')
      {
        vals[a] = b;
        for (int i = a; i <= N; ++i)
        {
          ps[i] = ps[i - 1] + mult * vals[i];
          mps[i] = mps[i - 1] + mult * vals[i] * i;
          mult *= -1;
        }
      }
    }

    cout << "Case #" << t << ": " << ans << '\n';
  }

  return 0;
}