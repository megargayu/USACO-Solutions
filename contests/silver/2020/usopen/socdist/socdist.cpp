#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

array<pair<long long, long long>, MAX_N> intervals;
int N, M;

bool check(long long D)
{
  long long prevCow = intervals[0].first;
  int numCows = 1;
  for (int i = 0; i < M;)
  {
    if (max(prevCow + D, intervals[i].first) <= intervals[i].second)
    {
      prevCow = max(prevCow + D, intervals[i].first);
      ++numCows;
      if (numCows == N) return true;
    } else ++i;
  }

  return numCows == N;
}

int main()
{
  ifstream fin("socdist.in");
  ofstream fout("socdist.out");

  fin >> N >> M;

  for (int i = 0; i < M; ++i)
    fin >> intervals[i].first >> intervals[i].second;

  sort(intervals.begin(), intervals.begin() + M);

  long long lo = 1, hi = 1e18, mid, ans;
  while (lo <= hi)
  {
    mid = lo + (hi - lo) / 2;
    if (check(mid))
    {
      ans = mid;
      lo = mid + 1;
    } else hi = mid - 1;
  }

  fout << ans << '\n';
}
