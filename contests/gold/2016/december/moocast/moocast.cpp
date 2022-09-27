#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000
#define pii pair<int, int>
#define f first
#define s second
#define ll long long

vector<pii> cows(MAX_N);
vector<vector<bool>> grid(MAX_N, vector<bool>(MAX_N));
vector<bool> visited(MAX_N);
int found = 0;
int N;
ll X;

ll square(ll num)
{
  return num * num;
}

void dfs(int v)
{
  visited[v] = true;
  ++found;

  for (int i = 0; i < N; i++) {
		if (visited[i] || !grid[v][i]) continue;
		dfs(i);
	}
}

bool works()
{
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      grid[i][j] = (square(cows[j].f - cows[i].f) + square(cows[j].s - cows[i].s) <= X);
  
  fill(visited.begin(), visited.end(), false);
  found = 0;
  dfs(0);

  return found == N;
}

int main()
{
  ifstream fin("moocast.in");
  ofstream fout("moocast.out");

  fin >> N;
  for (int i = 0; i < N; ++i)
    fin >> cows[i].f >> cows[i].s;

  ll lo = 0, hi = 1e10, ans;
  while (lo <= hi)
  {
    X = lo + (hi - lo) / 2LL;

    if (works())
    {
      ans = X;
      hi = X - 1;
    } else lo = X + 1;
  }

  fout << ans << '\n';
}
