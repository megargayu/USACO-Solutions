#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007LL
#define MAX_N 100000

struct Coord
{
  int x, y;
};

vector<Coord> posts(MAX_N);
map<int, map<int, int>> horiz, vert;
int main()
{
  ifstream fin("triangles.in");
  ofstream fout("triangles.out");

  int N;
  fin >> N;

  for (int i = 0; i < N; ++i)
  {
    fin >> posts[i].x >> posts[i].y;
    posts[i].x += 10000;
    posts[i].y += 10000;
  }

  sort(posts.begin(), posts.begin() + N, [](const Coord &a, const Coord &b)
  { 
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
  });

  for (int i = 0; i < N; ++i)
  {
    int j, ps = 0;
    vert[posts[i].x][posts[i].y] = ps;

    // get sum to the left
    for (j = i + 1; j < N && posts[j].x == posts[i].x; ++j)
    {
      ps += (j - i) * (posts[j].y - posts[j - 1].y);
      vert[posts[j].x][posts[j].y] = ps;
    }
    if (posts[j].x != posts[i].x) --j;

    int last = j;

    // get sum to the right
    ps = 0;
    for (j = j - 1; j >= i; --j)
    {
      ps += (last - j) * (posts[j + 1].y - posts[j].y);
      vert[posts[j].x][posts[j].y] += ps;
    }

    i = last;
  }

  sort(posts.begin(), posts.begin() + N, [](const Coord &a, const Coord &b)
  { 
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
  });

  for (int i = 0; i < N; ++i)
  {
    int j, ps = 0;
    horiz[posts[i].y][posts[i].x] = ps;

    // get sum to the left
    for (j = i + 1; j < N && posts[j].y == posts[i].y; ++j)
    {
      ps += (j - i) * (posts[j].x - posts[j - 1].x);
      horiz[posts[j].y][posts[j].x] = ps;
    }
    if (posts[j].y != posts[i].y) --j;

    int last = j;

    // get sum to the right
    ps = 0;
    for (j = j - 1; j >= i; --j)
    {
      ps += (last - j) * (posts[j + 1].x - posts[j].x);
      horiz[posts[j].y][posts[j].x] += ps;
    }

    i = last;
  }

  ll ans = 0;
  for (int i = 0; i < N; ++i)
  {
    ans += (vert[posts[i].x][posts[i].y] % MOD) * (horiz[posts[i].y][posts[i].x] % MOD);
    ans %= MOD;
  }

  fout << ans << '\n';

  return 0;
}