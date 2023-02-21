#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define MAX_N 1e5
#define INF 2e9

vector<pii> particles(MAX_N);
vector<int> smax(MAX_N + 1);

int main()
{
  freopen("moop.in", "r", stdin);
  freopen("moop.out", "w", stdout);

  int N;
  cin >> N;

  for (int i = 0; i < N; ++i)
    cin >> particles[i].first >> particles[i].second;

  sort(particles.begin(), particles.begin() + N);

  smax[N] = -INF;
  for (int i = N - 1; i >= 0; --i)
    smax[i] = max(particles[i].second, smax[i + 1]);

  int cmin = particles[0].second;
  int currComp = 1;
  for (int i = 1; i < N; ++i)
  {
    if (cmin > smax[i])
      ++currComp;

    cmin = min(particles[i].second, cmin);
  }

  cout << currComp << '\n';

  return 0;
}