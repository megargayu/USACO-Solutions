#include <bits/stdc++.h>
using namespace std;

#define MAX 40000
#define ll long long

struct Field
{
public:
  vector<ll> adj;
  bool visited = false;
  // distance from 1, 2, and N
  array<ll, 3> distances{-1, -1, -1};
};

array<Field, MAX> fields;

void minDistance(int start, int toUpdate)
{
  queue<ll> q;
  fields[start].distances[toUpdate] = 0;
  q.push(start);
  while (!q.empty())
  {
    int v = q.front(); q.pop();
    for (const auto &adjV : fields[v].adj)
      if (fields[adjV].distances[toUpdate] == -1)
      {
        fields[adjV].distances[toUpdate] = fields[v].distances[toUpdate] + 1;
        q.push(adjV);
      }
  }
}

int main()
{
  ofstream fout("piggyback.out");
  ifstream fin("piggyback.in");

  int B, E, P, N, M;
  fin >> B >> E >> P >> N >> M;

  int a, b;
  for (int i = 0; i < M; ++i)
  {
    fin >> a >> b;
    --a, --b;
    fields[a].adj.push_back(b);
    fields[b].adj.push_back(a);
  }

  minDistance(0, 0);
  minDistance(1, 1);
  minDistance(N - 1, 2);

  ll minEnergy = 9999999999;
  for (int i = 0; i < N; ++i)
  {
    minEnergy = min(minEnergy, B * fields[i].distances[0] + 
                               E * fields[i].distances[1] + 
                               P * fields[i].distances[2]);
  }

  fout << minEnergy << '\n';

  return 0;
}
