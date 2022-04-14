#include <bits/stdc++.h>
using namespace std;

#define MAX_XY 101
#define MAX_K 101

int X, Y, K, M;
int best = 10000;
array<array<array<bool, MAX_K>, MAX_XY>, MAX_XY> states;

void dfs(int b1, int b2, int depth)
{
  if (depth > K) return;
  if (states[b1][b2][depth]) return;
  states[b1][b2][depth] = true;

  best = min(best, abs(M - (b1 + b2)));

  // fill either pail
  if (b1 < X) dfs(X, b2, depth + 1);
  if (b2 < Y) dfs(b1, Y, depth + 1);

  // empty either pail
  if (b1 > 0) dfs(0, b2, depth + 1);
  if (b2 > 0) dfs(b1, 0, depth + 1);

  // pour b1 -> b2
  int newB1, newB2;
  if (b1 > 0)
  {
    if (b1 + b2 >= Y)
    {
      newB1 = b1 - (Y - b2);
      newB2 = Y;
    }
    else
    {
      newB2 = b1 + b2;
      newB1 = 0;
    }
    dfs(newB1, newB2, depth + 1);
  }

  // pour b2 -> b1
  if (b2 > 0)
  {
    if (b1 + b2 >= X)
    {
      newB2 = b2 - (X - b1);
      newB1 = X;
    }
    else
    {
      newB1 = b1 + b2;
      newB2 = 0;
    }
    dfs(newB1, newB2, depth + 1);
  }
}

int main()
{
  ifstream fin("pails.in");
  ofstream fout("pails.out");

  fin >> X >> Y >> K >> M;
  dfs(0, 0, 0);
  fout << best << '\n';

  return 0;
}
