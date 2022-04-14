#include <bits/stdc++.h>
using namespace std;

#define ll long long

// converts a guess into it's location
ll location(ll guess)
{
  return guess - guess/3 - guess/5 + guess/15;
}

int main()
{
  ifstream fin("moobuzz.in");
  ofstream fout("moobuzz.out");

  ll N;
  fin >> N;

  ll lo = 0, hi = 2000000000, mid, loc;
  while (lo <= hi)
  {
    mid = lo + (hi - lo) / 2;
    loc = location(mid);

    if (loc < N) lo = mid + 1;
    else if (loc > N) hi = mid - 1;
    else
    {
      while (mid % 3 == 0 || mid % 5 == 0) --mid;
      fout << mid << '\n';
      break;
    }
  }

  return 0;
}
