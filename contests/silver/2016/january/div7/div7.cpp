// #include <bits/stdc++.h> // for some reason the USACO grader doesn't like this for this problem?
#include <fstream>
#include <vector>
using namespace std;

#define MAX_N 50000
#define ll long long

vector<ll> cows(MAX_N + 1);

int main()
{
  ifstream fin("div7.in");
  ofstream fout("div7.out");

  int N;
  fin >> N;

  cows[0] = 0;

  for (int i = 1; i <= N; ++i)
  {
    fin >> cows[i];
  }

  for (int i = 1; i <= N; ++i)
  {
    cows[i] += cows[i - 1];
    cows[i] %= 7;
  }

  vector<int> firstSum(7, -1);
  int answer = 0;
  for (int i = 1; i <= N; ++i)
  {
    if (firstSum[cows[i]] != -1)
      answer = max(answer, i - firstSum[cows[i]]);
    else
      firstSum[cows[i]] = i;
  }

  fout << answer << '\n';

  return 0;
}
