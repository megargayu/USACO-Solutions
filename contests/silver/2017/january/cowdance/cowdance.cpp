#include <bits/stdc++.h>
using namespace std;

#define MAX_N 10000

array<int, MAX_N> durations;
int N, Tmax;

bool simulate(int K)
{
  priority_queue<int, vector<int>, greater<int>> q;
  int lastTime = 0;

  for (int i = 0; i < N; ++i)
  {
    if (q.size() == K)
    {
      lastTime = q.top();
      q.pop();
    }

    if (lastTime + durations[i] > Tmax)
      return false;

    q.push(lastTime + durations[i]);
  }

  return true;
}

int main()
{
  ifstream fin("cowdance.in");
  ofstream fout("cowdance.out");

  fin >> N >> Tmax;

  for (int i = 0; i < N; ++i)
    fin >> durations[i];

  int lo = 1, hi = N, mid, ans;
  while (lo <= hi)
  {
    mid = lo + (hi - lo) / 2;
    if (simulate(mid))
    {
      ans = mid;
      hi = mid - 1;
    } else lo = mid + 1;
  }

  fout << ans << '\n';
}
