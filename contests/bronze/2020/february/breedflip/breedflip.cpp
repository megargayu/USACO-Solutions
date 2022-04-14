#include <bits/stdc++.h>
using namespace std;

int main()
{
  ifstream fin("breedflip.in");
  ofstream fout("breedflip.out");

  int N;
  string orig, changed;
  fin >> N >> orig >> changed;

  int ans = 0;
  bool inRange = false;
  for (int i = 0; i < N; ++i)
  {
    if (orig[i] != changed[i])
    {
      if (!inRange) inRange = true, ++ans; // start new interval
      // otherwise keep going
    }
    else
    {
      if (inRange) inRange = false; // stop interval
      // otherwise interval is already stopped
    }
  }

  fout << ans << '\n';
  
  return 0;
}
