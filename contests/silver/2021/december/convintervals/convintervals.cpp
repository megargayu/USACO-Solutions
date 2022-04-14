#include <bits/stdc++.h>
using namespace std;

#define MAX_M 5000
#define ll long long

array<ll, MAX_M + 1> nstarts, nends;
array<ll, 2 * MAX_M + 2> pSums;

int main()
{
  int N, M;
  cin >> N >> M;

  int a, b;
  for (int i = 0; i < N; ++i)
  {
    cin >> a >> b;
    ++nstarts[a], ++nends[b];
  }

  for (int i = 0; i <= M; ++i)
    for (int j = 0; j <= M; ++j)
    {
      pSums[i + j] += nstarts[i] * nstarts[j];
      pSums[i + j + 1] -= nends[i] * nends[j];
    }
  
  ll last = 0;
  for (int i = 0; i <= 2 * M; ++i)
  {
    last += pSums[i];
    cout << last << '\n';
  }

  return 0;
}