#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007LL
#define MAX_N 100000

struct Coord
{
  int x, y;
};

struct mi {
  int v; explicit operator int() const { return v; }
  mi(ll _v) : v(_v%MOD) { v += (v<0)*MOD; }
  mi() : mi(0) {}
};
mi operator+(mi a, mi b) { return mi(a.v+b.v); }
mi operator-(mi a, mi b) { return mi(a.v-b.v); }
mi operator*(mi a, mi b) { return mi((ll)a.v*b.v); }
ostream &operator<<(ostream&s, mi a) { s << a.v; return s; }

vector<Coord> posts(MAX_N);
map<int, map<int, int>> xps, yps;
map<int, int> maxX, maxY;
int main() {
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
    auto found = maxY.find(posts[i].x);
    if (found != maxY.end()) found->second = max(found->second, posts[i].y);
    else maxY.insert({ posts[i].x, posts[i].y });
  }

  // loop through each x value to fill in y values
  for (int i = 0; i < N; ++i)
  {
    int j, ps = 0;
    yps[posts[i].x][posts[i].y] = ps;
    for (j = i + 1; j < N && posts[j].x == posts[i].x; ++j)
    {
      ps += posts[j].y - posts[i].y;
      yps[posts[j].x][posts[j].y] = ps;
    }
    i = j - 1;
  }

  sort(posts.begin(), posts.begin() + N, [](const Coord &a, const Coord &b)
  { 
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
  });

  for (int i = 0; i < N; ++i)
  {
    auto found = maxX.find(posts[i].y);
    if (found != maxX.end()) found->second = max(found->second, posts[i].x);
    else maxX.insert({ posts[i].y, posts[i].x });
  }

  // loop through each y value to fill in x values
  for (int i = 0; i < N; ++i)
  {
    int j, ps = 0;
    xps[posts[i].y][posts[i].x] = ps;
    for (j = i + 1; j < N && posts[j].y == posts[i].y; ++j)
    {
      ps += posts[j].x - posts[i].x;
      xps[posts[j].y][posts[j].x] = ps;
    }
    i = j - 1;
  }

  // TODO: prefix sums might be wrong here
  mi ans = 0;
  for (int i = 0; i < N; ++i)
  {
    mi left = xps[posts[i].y][posts[i].x];
    mi right = xps[posts[i].y][maxX[posts[i].y]] - left;
    mi down = yps[posts[i].x][posts[i].y];
    mi up = yps[posts[i].x][maxY[posts[i].x]] - down;
    //cout << '(' << posts[i].x << ", " << posts[i].y << ") " << left << ' ' << right << ' ' << down << ' ' << up << '\n';
    ans = ans + up * right;
    ans = ans + right * down;
    ans = ans + down * left;
    ans = ans + left * up; 
  }

  fout << ans << '\n';
  return 0;
}
