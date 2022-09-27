#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000
#define MAX_K 20

vector<char> moves(MAX_N);

// 0 = Hoof, 1 = Paper, 2 = Scissors
vector<vector<vector<int>>> dp(MAX_N + 1, vector<vector<int>>(MAX_K + 1, vector<int>(3)));

bool wins(int n, int g)
{
  switch (moves[n])
  {
  case 'P':
    return g == 2;
  case 'S':
    return g == 0;
  case 'H':
    return g == 1;
  default:
    return false;
  }
}

int main()
{
  ofstream fout("hps.out");
  ifstream fin("hps.in");

  int N, K;
  fin >> N >> K;

  int numP = 0, numH = 0, numS = 0;
  for (int i = 0; i < N; ++i)
  {
    fin >> moves[i];
  }

  for (int n = 0; n <= N; ++n)
    for (int k = 0; k <= K; ++k)
      for (int g = 0; g < 3; ++g)
      {
        const int g1 = (g + 1) % 3;
        const int g2 = (g + 2) % 3;
        const bool winsGame = wins(n, g);

        dp[n][k][g] = winsGame;
        if (n > 0)
        {
          dp[n][k][g] = max(dp[n][k][g], dp[n - 1][k][g] + winsGame);

          if (k > 0)
            dp[n][k][g] = max(dp[n][k][g], max(dp[n - 1][k - 1][g1] + winsGame, dp[n - 1][k - 1][g2] + winsGame));
        } 
      }

  fout << max(max(dp[N][K][0], dp[N][K][1]), dp[N][K][2]) << '\n';

  return 0;
}