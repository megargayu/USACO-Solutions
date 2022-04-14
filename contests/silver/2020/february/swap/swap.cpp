#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000
#define MAX_M 100

vector<int> cows(MAX_N), p(MAX_N);
vector<vector<int>> cycles(MAX_N);
int main()
{
  ifstream fin("swap.in");
  ofstream fout("swap.out");

  int N, M, K;
  fin >> N >> M >> K;

  for (int i = 0; i < N; ++i) 
    cows[i] = i;

  int a, b;
  for (int i = 0; i < M; ++i)
  {
    fin >> a >> b;
    --a, --b;

    // reverse from a to b
    for (int j = a; j <= (a + b) / 2; ++j)
      swap(cows[j], cows[b - j + a]);
  }

  for (int i = 0; i < N; ++i)
    p[cows[i]] = i;

  vector<int> component(MAX_N), posInCycle(MAX_N);
  int currComponent = 0;
  fill(component.begin(), component.end(), -1);
  for (int i = 0; i < N; ++i)
  {
    if (component[i] == -1)
    {
      component[i] = currComponent;
      cycles[currComponent].push_back(i);
      int j = p[i];
      if (j != i) posInCycle[j] = 1;
      
      while (j != i)
      {
        cycles[currComponent].push_back(j);
        component[j] = currComponent;
        if (p[j] != i) posInCycle[p[j]] = posInCycle[j] + 1;
        j = p[j];
      }

      ++currComponent;
    }
  }

  vector<int> ans(MAX_N);
  for (int i = 0; i < N; ++i)
  {
    int mod = (posInCycle[i] + K) % cycles[component[i]].size();
    ans[cycles[component[i]][mod]] = i;
  }

  for (int i = 0; i < N; ++i)
    fout << ans[i] + 1 << '\n';

  return 0;
}
