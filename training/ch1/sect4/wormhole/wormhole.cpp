/*
ID: megarga1
TASK: wormhole
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int N;
vector<pii> wormholes(12);
vector<int> paired(12, -1);

bool cycle()
{
  for (int start = 0; start < N; start++)
  {
    int pos = start;
    bool isCycle = true;
    for (int count = 0; count < N; count++)
    {
      const int o = paired[pos];

      // if not paired with another wormhole or the next wormhole has a different y value
      // (i.e. there is no wormhole to the right), then bessie will go on infinitely +x from this
      // start, so we can break.
      if (o == -1 || (o == N - 1 || wormholes[o + 1].second != wormholes[o].second))
      {
        isCycle = false;
        break;
      }

      pos = o + 1;
    }

    if (isCycle)
      return true;
  }

  return false;
}

int dfs()
{
  int ans = 0;

  int i;
  for (; i < N; ++i)
    if (paired[i] == -1)
      break;

  if (i >= N)
    return cycle();

  for (int j = i + 1; j < N; ++j)
    if (paired[j] == -1)
    {
      paired[j] = i;
      paired[i] = j;
      ans += dfs();
      paired[i] = paired[j] = -1;
    }
  
  return ans;
}

int main()
{
  freopen("wormhole.in", "r", stdin);
  freopen("wormhole.out", "w", stdout);

  cin >> N;

  for (int i = 0; i < N; ++i)
    cin >> wormholes[i].first >> wormholes[i].second;

  sort(wormholes.begin(), wormholes.begin() + N, [](const pii &a, const pii &b)
       {
    if (a.second == b.second)
      return a.first < b.first;
    
    return a.second < b.second; });

  cout << dfs() << '\n';

  return 0;
}