#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

vector<int> scores(MAX_N), ans;
int main()
{
  ifstream fin("homework.in");
  ofstream fout("homework.out");

  int N;
  fin >> N;
  for (int i = 0; i < N; ++i) fin >> scores[i];

  int sufSum = scores[N - 1];
  int minNum = scores[N - 1];
  double best = -1;
  
  for (int K = N - 2; K >= 1; --K)
  {
    sufSum += scores[K];
    minNum = min(minNum, scores[K]);

    double score = static_cast<double>(sufSum - minNum) / 
                   static_cast<double>(N - K - 1);
    if (score > best)
    {
      best = score;
      ans.clear();
      ans.push_back(K);
    }
    else if (score == best)
    {
      ans.push_back(K);
    }
  }

  sort(ans.begin(), ans.end());

  for (const int &K : ans)
    fout << K << '\n';

  return 0;
}
