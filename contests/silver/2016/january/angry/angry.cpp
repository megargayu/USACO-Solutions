#include <bits/stdc++.h>
using namespace std;

#define MAX_N 50000

array<long long, MAX_N> haybales;
int N, K;

bool simulate(long long R)
{
  long long exploded = -1;
  int cows = 0;
  // move cow to right most of current haybale so it explodes as much as possible
  // while still exploding this haybale
  for (int i = 0; i < N; ++i)
  {
    if (exploded < haybales[i])
    {
      exploded = haybales[i] + 2 * R;
      ++cows;
    }

    if (cows > K) return false;
  }

  return true;
}

int main()
{
  ifstream fin("angry.in");
  ofstream fout("angry.out");

  fin >> N >> K;

  for (int i = 0; i < N; ++i)
    fin >> haybales[i];
  
  sort(haybales.begin(), haybales.begin() + N);

  long long lo = 0, hi = 500000000, mid, ans;
  while (lo <= hi)
  {
    mid = lo + (hi - lo) / 2;
    if (simulate(mid))
    {
      ans = mid;
      hi = mid - 1; // try lower radius
    } else lo = mid + 1;
  }

  fout << ans << '\n';
}
