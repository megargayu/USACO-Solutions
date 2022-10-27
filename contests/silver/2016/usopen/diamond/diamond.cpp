#include <bits/stdc++.h>
using namespace std;

#define MAX_N 50000

vector<int> d(MAX_N), to(MAX_N), maxV(MAX_N + 1);

int main()
{
  ifstream fin("diamond.in");
  ofstream fout("diamond.out");

  int N, K;
  fin >> N >> K;

  for (int i = 0; i < N; ++i)
    fin >> d[i];

  sort(d.begin(), d.begin() + N);

  int j = 0;
  for (int i = 0; i < N; ++i)
  {
    j = max(j, i);

    while (j < N && d[j] - d[i] <= K)
      ++j;
    --j;

    to[i] = j;
  }

  maxV[N] = 0;
  maxV[N - 1] = to[N - 1] - (N - 1);
  for (int i = N - 2; i >= 0; --i)
    maxV[i] = max(to[i] - i + 1, maxV[i + 1]);

  int ans = 0;
  for (int i = 0; i < N; ++i)
    ans = max(ans, (to[i] - i + 1) + maxV[to[i] + 1]);

  fout << ans << '\n';

  return 0;
}