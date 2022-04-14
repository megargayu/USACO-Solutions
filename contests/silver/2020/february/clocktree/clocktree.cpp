#include <bits/stdc++.h>
using namespace std;

#define MAX_N 2500

vector<int> orignalRooms(MAX_N), rooms(MAX_N);
vector<vector<int>> adj(MAX_N);
vector<bool> visited(MAX_N);

void dfs(int from, int v)
{
  visited[v] = true;
  rooms[v] += 1;
  
  // leaf node has only 1 connection
  if (from != -1 && adj[v].size() == 1)
  {
    // have to add 1 to go back
    rooms[adj[v][0]] = rooms[adj[v][0]] + (12 - rooms[v]) + 1;
    if (rooms[adj[v][0]] > 12) rooms[adj[v][0]] -= 12;
    rooms[v] = 12;
    return;
  }

  for (const auto &w : adj[v])
    if (!visited[w])
      dfs(v, w);

  // this is now a leaf node!
  if (from != -1)
  {
    rooms[from] = rooms[from] + (12 - rooms[v]) + 1;
    if (rooms[from] > 12) rooms[from] -= 12;
    rooms[v] = 12;
  }
}

int main()
{
  ifstream fin("clocktree.in");
  ofstream fout("clocktree.out");

  int N;
  fin >> N;

  for (int i = 0; i < N; ++i)
    fin >> orignalRooms[i];

  int a, b;
  for (int i = 0; i < N - 1; ++i)
  {
    fin >> a >> b;
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int ans = 0;
  for (int i = 0; i < N; ++i)
  {
    fill(visited.begin(), visited.end(), false);
    copy(orignalRooms.begin(), orignalRooms.end(), rooms.begin());
    rooms[i] -= 1;
    dfs(-1, i);

    // if the room is 1, Bessie could just not come back to the room and the
    // clock in that room would therefore be 12.
    if (rooms[i] == 1 || rooms[i] == 12)
      ++ans;
  }

  fout << ans << '\n';

  return 0;
}
