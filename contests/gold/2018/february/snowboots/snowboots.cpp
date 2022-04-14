#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1e5

struct Boot
{
  int depth, step, ind;
};

vector<int> tiles(MAX_N);
vector<pair<int, int>> sortedTiles(MAX_N);
vector<bool> answer(MAX_N);
vector<Boot> boots(MAX_N);
vector<int> l(MAX_N), r(MAX_N);
int maxJump = 1;

void landmine(int v)
{
  r[l[v]] = r[v];
  l[r[v]] = l[v];
  maxJump = max(maxJump, r[v] - l[v]);
}

int main()
{
  ifstream fin("snowboots.in");
  ofstream fout("snowboots.out");

  int N, B;
  fin >> N >> B;

  for (int i = 0; i < N; ++i) l[i] = i - 1;
  for (int i = 0; i < N; ++i) r[i] = i + 1;

  for (int i = 0; i < N; ++i)
  {
    fin >> tiles[i];
    sortedTiles[i] = { tiles[i], i };
  }

  sort(sortedTiles.begin(), sortedTiles.begin() + N, greater<pair<int, int>>());

  for (int i = 0; i < B; ++i)
  {
    fin >> boots[i].depth >> boots[i].step;
    boots[i].ind = i;
  } 

  sort(boots.begin(), boots.begin() + B, [](const auto &a, const auto &b)
  { return a.depth > b.depth; });

  int currSortedTile = 0;
  for (int b = 0; b < B; ++b)
  {
    while (boots[b].depth < sortedTiles[currSortedTile].first)
    {
      // landmine the actual index of the tile, not the sorted version
      landmine(sortedTiles[currSortedTile].second);
      ++currSortedTile;
    }
    
    answer[boots[b].ind] = maxJump <= boots[b].step;
  }

  for (int i = 0; i < B; ++i)
    fout << answer[i] << '\n';

  return 0;
}
