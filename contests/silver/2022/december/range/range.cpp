// NOTE: completely broken

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 300
#define INF 2e9

vector<vector<int>> r(MAX_N, vector<int>(MAX_N));
vector<int> aV(MAX_N);
vector<vector<int>> maxV(MAX_N, vector<int>(MAX_N)), minV(MAX_N, vector<int>(MAX_N));

bool checkR(int a, int b, int p)
{
  // cannot be max or min
  if (r[a][b] == r[a][b - 1])
  {
    if (p > maxV[a][b] || p < minV[a][b])
      return false;
    
    return true;
  }
  else // either new max or new min
  {
    if (p > maxV[a][b] && p - minV[a][b] == r[a][b])
      return true;
    
    if (p < minV[a][b] && maxV[a][b] - p == r[a][b])
      return true;
    
    return false;
  }
}

int main()
{
  int N;
  cin >> N;

  for (int i = 0; i < N; ++i)
    for (int j = i; j < N; ++j)
      cin >> r[i][j];

  aV[0] = 1;
  aV[1] = aV[0] + r[0][1];

  for (int a = 2; a < N; ++a)
  {
    int p1 = aV[a - 1] + r[a - 1][a],
        p2 = aV[a - 1] - r[a - 1][a];

    for (int i = a - 2; i >= 0; --i)
    {
      bool is1 = checkR(i, a, p1), is2 = checkR(i, a, p2);
      if (is1 && is2)
        continue;

      assert(is1 || is2);

      aV[a] = is1 ? p1 : p2;
      break;
    }
  }

  return 0;
}
