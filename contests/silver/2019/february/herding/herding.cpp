#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1e5

vector<int> a(MAX_N);

int main()
{
  ofstream fout("herding.out");
  ifstream fin("herding.in");

  int N;
  fin >> N;

  for (int i = 0; i < N; ++i)
    fin >> a[i];
  
  sort(a.begin(), a.begin() + N);

  int minAns = 0;
  if (a[N - 2] - a[0] == N - 2 && a[N - 1] - a[N - 2] > 2)
    minAns = 2;
  else if (a[N - 1] - a[1] == N - 2 && a[1] - a[0] > 2)
    minAns = 2;
  else
  {
    int j = 0, best = 0;
    for (int i = 0; i < N; ++i)
    {
      while (j < N - 1 && a[j + 1] - a[i] <= N - 1)
        ++j;
      best = max(best, j - i + 1);
    }
    minAns = N - best;
  }

  int maxAns = max(a[N - 1] - a[1], a[N - 2] - a[0]) - (N - 2);

  fout << minAns << '\n' << maxAns << '\n';

  return 0;
}
