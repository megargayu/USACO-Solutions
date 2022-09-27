#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define MAX_N 1e5
#define INF 2e9

vector<int> cows(MAX_N);
int main()
{
  ifstream fin("cbarn.in");
  ofstream fout("cbarn.out");

  int N;
  fin >> N;

  for (int i = 0; i < N; ++i)
    fin >> cows[i];

  int active = N, min = INF, minI;
  for (int i = 0; i < N; ++i)
  {
    active += cows[i] - 1;
    if (active < min)
    {
      min = active;
      minI = i;
    }
  }

  minI = minI == N - 1 ? 0 : minI + 1;
  vector<pii> activeC;
  int currActive = 0;
  ll ans = 0;
  for (int i = minI; i < N + minI; ++i)
  {
    int ind = i % N;
    if (cows[ind] > 0) activeC.push_back({ i, cows[ind] }); // pick up all cows here
    if (activeC.size() == 0) continue;

    // drop off one cow here
    ans += (i - activeC[currActive].first) * (i - activeC[currActive].first);
    --activeC[currActive].second;
    if (activeC[currActive].second == 0) ++currActive;
  }

  fout << ans << '\n';

  return 0;
}