// https://cses.fi/problemset/task/1633

#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<ll> numWays(1e6 + 2);
int main()
{
  int N;
  cin >> N;

  numWays[1] = 1;
  for (int i = 2; i <= N + 1; ++i)
  {
    for (int j = 1; j <= 6 && i - j >= 1; ++j)
      numWays[i] += numWays[i - j];

    numWays[i] %= (ll)1e9 + 7;
  }

  cout << numWays[N + 1] << '\n';

  return 0;
}
