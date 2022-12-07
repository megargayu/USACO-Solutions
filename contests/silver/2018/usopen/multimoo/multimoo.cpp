#include <bits/stdc++.h>
using namespace std;

#define MAX_N 250

const array<int, 4> dr{-1, 1, 0, 0},
    dc{0, 0, -1, 1};

const array<int, 4> dr2{1, 0},
    dc2{0, 1};

int N;
int currComp = 0;
vector<vector<int>> grid(MAX_N, vector<int>(MAX_N));
vector<vector<bool>> vis(MAX_N, vector<bool>(MAX_N));

vector<vector<int>> compGrid(MAX_N, vector<int>(MAX_N));

vector<set<int>> adj(MAX_N * MAX_N);
map<int, set<int>> pairVis;
vector<int> compSize(MAX_N * MAX_N), compNum(MAX_N * MAX_N);
set<int> vis2;

bool inGrid(int r, int c)
{
  return 0 <= r && r < N && 0 <= c && c < N;
}

void flood(int r, int c)
{
  vis[r][c] = true;
  ++compSize[currComp];
  compGrid[r][c] = currComp;
  for (int i = 0; i < 4; ++i)
  {
    const int nr = r + dr[i], nc = c + dc[i];
    if (inGrid(nr, nc) && grid[nr][nc] == grid[r][c] && !vis[nr][nc])
      flood(nr, nc);
  }
}

int dfs(int v, int a, int b)
{
  vis2.insert(v);
  int ans = compSize[v];

  for (const auto &w : adj[v])
    if ((compNum[w] == a || compNum[w] == b) && vis2.find(w) == vis2.end())
    {
      ans += dfs(w, a, b);
    }

  return ans;
}

int main()
{
  freopen("multimoo.in", "r", stdin);
  freopen("multimoo.out", "w", stdout);

  cin >> N;

  for (int r = 0; r < N; ++r)
    for (int c = 0; c < N; ++c)
      cin >> grid[r][c];

  for (int r = 0; r < N; ++r)
    for (int c = 0; c < N; ++c)
      if (!vis[r][c])
      {
        compNum[currComp] = grid[r][c];
        flood(r, c);
        ++currComp;
      }

  cout << *max_element(compSize.begin(), compSize.begin() + currComp) << '\n';

  for (int r = 0; r < N; ++r)
    for (int c = 0; c < N; ++c)
      for (int i = 0; i < 2; ++i)
      {
        const int nr = r + dr2[i], nc = c + dc2[i];
        if (inGrid(nr, nc) && compGrid[nr][nc] != compGrid[r][c])
        {
          adj[compGrid[r][c]].insert(compGrid[nr][nc]);
          adj[compGrid[nr][nc]].insert(compGrid[r][c]);
        }
      }

  // only pair together nodes that are adjacent
  int ans2 = 0;
  for (int v = 0; v < currComp; ++v)
    for (const auto &w : adj[v])
      if (pairVis[compNum[v]].find(compNum[w]) == pairVis[compNum[v]].end())
      {
        vis2.clear();
        ans2 = max(ans2, dfs(v, compNum[v], compNum[w]));
        pairVis[compNum[v]].insert(compNum[w]);
        pairVis[compNum[w]].insert(compNum[v]);
      }

  cout << ans2 << '\n';

  return 0;
}