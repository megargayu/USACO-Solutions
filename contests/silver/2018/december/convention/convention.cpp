#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX_N 100000

int N, M, C;
vector<ll> times(MAX_N);

bool possible(ll waitTime)
{
  int busses = 1, firstIndex = 0;
  ll firstArrival = times[0];
  for (int i = 1; i < N; ++i)
    if (times[i] - firstArrival > waitTime || i + 1 - firstIndex > C)
    {
      ++busses;
      firstArrival = times[i];
      firstIndex = i;
    }

  return busses <= M;
}

int main()
{
  ifstream fin("convention.in");
  ofstream fout("convention.out");

  fin >> N >> M >> C;
  
  for (int i = 0; i < N; ++i)
    fin >> times[i];
  
  sort(times.begin(), times.begin() + N);

  ll lo = 0, hi = 1000000001, mid, ans = -1;
  while (lo <= hi)
  {
    mid = lo + (hi - lo) / 2;
    if (possible(mid))
    {
      ans = mid;
      hi = mid - 1;
    } else
    {
      lo = mid + 1;
    }
  }

  fout << ans << '\n';

  return 0;
}
