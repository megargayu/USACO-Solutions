#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000

vector<int> trees(MAX_N);
int main()
{
  ifstream fin("berries.in");
  ofstream fout("berries.out");

  int N, K;
  fin >> N >> K;
  for (int i = 0; i < N; ++i)
    fin >> trees[i];

  sort(trees.begin(), trees.end(), greater<int>());

  int answer = 0;
  for (int b = 1; b <= 1000; ++b)
  {
    vector<int> treesC(trees), baskets;
    int total = 0;
    for (int i = 0; i < N; ++i)
    {
      if (treesC[i] < b) break;

      while (treesC[i] >= b)
      {
        treesC[i] -= b;
        baskets.push_back(b);
        ++total;
      }
    }

    if (total < K)
    {
      sort(treesC.begin(), treesC.end(), greater<int>());

      for (int i = 0; i < K - total; ++i)
      {
        baskets.push_back(treesC[i]);
      }

      int sum = 0;
      for (int i = K / 2; i < K; ++i)
      {
        sum += baskets[i];
      }
      answer = max(answer, sum);
    }
    else
    {
      answer = max(answer, K / 2 * b);
    }
  }

  fout << answer << '\n';

  return 0;
}
