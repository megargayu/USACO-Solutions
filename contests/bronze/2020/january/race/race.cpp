#include <bits/stdc++.h>
using namespace std;

int K, N, X;

int solve()
{
  int i = 0, j = 0, time = 0;
  for (int speed = 1;; ++speed)
  {
    i += speed;
    ++time;
    if (i + j >= K)
      return time;

    if (speed >= X)
    {
      j += speed;
      ++time;
      if (i + j >= K)
        return time;
    }
  }

  return -1;
}

int main()
{
  ofstream fout("race.out");
  ifstream fin("race.in");

  fin >> K >> N;

  for (int i = 0; i < N; ++i)
  {
    fin >> X;
    fout << solve() << '\n';
  }

  return 0;
}
