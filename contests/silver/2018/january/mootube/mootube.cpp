#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <queue>

using namespace std;

#define MAX_N 5001

struct Connection
{
public:
  int to;
  int weight;
};

array<vector<Connection>, MAX_N> graph;
array<bool, MAX_N> visited;
int N, Q;

int solve(int v, int k)
{
  visited.fill(false);
  visited[v] = true;

  queue<const Connection *> q;
  for (const Connection &c : graph[v])
    if (c.weight >= k)
      q.push(&c);

  int result = 0;
  while (!q.empty())
  {
    const Connection *c = q.front();
    visited[c->to] = true;
    ++result;
    for (const Connection &adj : graph[q.front()->to])
      if (adj.weight >= k && !visited[adj.to])
        q.push(&adj);

    q.pop();
  }

  return result;
}

int main()
{
  ofstream fout("mootube.out");
  ifstream fin("mootube.in");

  fin >> N >> Q;

  for (int i = 0; i < N - 1; ++i)
  {
    int from, to, weight;
    fin >> from >> to >> weight;
    graph[from].push_back({to, weight});
    graph[to].push_back({from, weight});
  }

  for (int i = 0; i < Q; ++i)
  {
    int k, v;
    fin >> k >> v;
    fout << solve(v, k) << '\n';
  }

  return 0;
}
