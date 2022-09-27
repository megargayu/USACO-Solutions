#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll N, K, M;

bool check(ll X)
{
  ll G = 0;
  for (ll t = 0; t < K;)
  {
    const ll Y = (N - G) / X;
    if (Y <= M)
    {
      // check if the number of gallons plus adding M gallons for the rest of the days will
      // fulfill the amount of gallons owed
      return G + M * (K - t) >= N;
    }

    const ll numRepeat = ((N - G) % X) / Y + 1;
    t += numRepeat;
    G += numRepeat * Y;
  }

  return G >= N;
}

int main()
{
  ifstream fin("loan.in");
  ofstream fout("loan.out");

  fin >> N >> K >> M;
  
  ll lo = 1, hi = N, X, ans;
  while (lo <= hi)
  {
    X = lo + (hi - lo) / 2;
    if (check(X))
    {
      ans = X;
      lo = X + 1; // maximize X
    } else hi = X - 1;
  }

  fout << ans << '\n';

  return 0;
}