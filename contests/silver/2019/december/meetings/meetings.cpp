#include <bits/stdc++.h>
using namespace std;

#define MAX_N 5e4
#define pii pair<int, int>

struct Cow
{
  int w, x, d;
};

vector<Cow> cows(MAX_N);
vector<Cow> leftC(MAX_N), rightC(MAX_N);
vector<pii> poi(MAX_N * 50);

int main()
{
  ifstream fin("meetings.in");
  ofstream fout("meetings.out");

  int N, L;
  fin >> N >> L;

  int numLeft = 0, totalW = 0;
  for (int i = 0; i < N; ++i)
  {
    fin >> cows[i].w >> cows[i].x >> cows[i].d;
    numLeft += cows[i].d == -1;
    totalW += cows[i].w;
  }
  
  sort(cows.begin(), cows.begin() + N, [](const Cow &a, const Cow &b)
  { return a.x < b.x; });

  int leftI = 0, rightI = 0;
  for (int i = 0; i < N; ++i)
  {
    if (cows[i].d == -1) leftC[leftI++] = cows[i];
    else rightC[rightI++] = cows[i];
  }

  int poiI = 0;
  for (int i = 0; i < leftI; ++i)
    poi[poiI++] = {leftC[i].x, cows[i].w};

  for (int i = 0; i < rightI; ++i)
    poi[poiI++] = {L - rightC[i].x, cows[leftI + i].w};

  sort(poi.begin(), poi.begin() + poiI, [](const pii &a, const pii &b)
  { return a.first < b.first; });

  int T = -1, w = 0;
  for (int i = 0; i < poiI; ++i)
  {
    w += poi[i].second;
    if (w * 2 >= totalW)
    {
      T = poi[i].first;
      break;
    }
  }

  assert(T != -1);

  int ans = 0;
  int i = 0, j = 0;
  for (int l = 0; l < rightI; ++l)
  {
    while (i < leftI && leftC[i].x < rightC[l].x)
      ++i;
    
    while (j < leftI && leftC[j].x <= rightC[l].x + T * 2)
      ++j;

    ans += j - i;
  }

  fout << ans << '\n';

  return 0;
}