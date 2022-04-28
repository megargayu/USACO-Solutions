#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1e5

struct Cow
{
  int time, num;
};

vector<Cow> cows(MAX_N);
int main() 
{
  ifstream fin("pairup.in");
  ofstream fout("pairup.out");

  int N;
  fin >> N;

  for (int i = 0; i < N; ++i)
    fin >> cows[i].num >> cows[i].time;

  sort(cows.begin(), cows.begin() + N, [](const Cow &a, const Cow &b)
  { return a.time < b.time; });

  int p1 = 0, p2 = N - 1, maxPair = 0;
  while (p1 <= p2)
  {
    maxPair = max(maxPair, cows[p1].time + cows[p2].time);

    // skip the rest of calculations between p1 and p2, as they will always
    // be the same as the current sum
    if (cows[p1].num < cows[p2].num)
    {
      cows[p2].num -= cows[p1].num;
      ++p1;
    }
    else if (cows[p2].num < cows[p1].num)
    {
      cows[p1].num -= cows[p2].num;
      --p2;
    }
    else ++p1, --p2;
  }
  

  fout << maxPair << '\n';

  return 0;
}
