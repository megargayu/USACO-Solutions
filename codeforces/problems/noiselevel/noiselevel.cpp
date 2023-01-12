// https://codeforces.com/contest/847/problem/I

#include <bits/stdc++.h>
using namespace std;

#define MAX_NM 250
#define ll long long

const vector<int> dr{0, 1, 0, -1},
    dc{1, 0, -1, 0};

struct Pt
{
  int r, c;
};

int n, m;
ll q, p;

vector<vector<char>> cells(MAX_NM, vector<char>(MAX_NM));
vector<vector<ll>> noise(MAX_NM, vector<ll>(MAX_NM, 0));

bool inGrid(int r, int c)
{
  return 0 <= r && r < n && 0 <= c && c < m;
}

void bfs(int r, int c, ll mq)
{
  vector<vector<bool>> vis(MAX_NM, vector<bool>(MAX_NM));
  queue<pair<Pt, ll>> qu;
  qu.push({{r, c}, mq});
  vis[r][c] = true;

  while (!qu.empty())
  {
    const auto top = qu.front();
    qu.pop();

    const Pt &pt = top.first;
    const int &cq = top.second;

    noise[pt.r][pt.c] += cq;

    // cout << cq << ' ' << pt.r << ' ' << pt.c << ' ' << noise[pt.r][pt.c] << '\n';

    for (int i = 0; i < 4; ++i)
    {
      int nr = pt.r + dr[i], nc = pt.c + dc[i];
      if (inGrid(nr, nc) && !vis[nr][nc] && cells[nr][nc] != '*')
      {
        vis[nr][nc] = true;
        if (cq > 1)
          qu.push({{nr, nc}, cq / 2});
      }
    }
  }
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> q >> p;
  // cout << n << m << q << p << '\n';

  for (int r = 0; r < n; ++r)
    for (int c = 0; c < m; ++c)
      cin >> cells[r][c];

  for (int r = 0; r < n; ++r)
    for (int c = 0; c < m; ++c)
      if (cells[r][c] != '.' && cells[r][c] != '*')
        bfs(r, c, (cells[r][c] - 'A' + 1LL) * q);

  int ans = 0;
  for (int r = 0; r < n; ++r)
    for (int c = 0; c < m; ++c)
      ans += noise[r][c] > p;

  cout << ans << '\n';

  return 0;
}