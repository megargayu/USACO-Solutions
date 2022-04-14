#include <bits/stdc++.h>
using namespace std;

#define MAX_N 50000

vector<int> elsie, bessie;
array<bool, MAX_N * 2> elsieHas;

int main()
{
  ofstream fout("highcard.out");
  ifstream fin("highcard.in");

  int N;
  fin >> N;
  elsie.resize(N), bessie.resize(N);

  int card;
  for (int i = 0; i < N; ++i)
  {
    fin >> card;
    elsieHas[card - 1] = true;
  }

  int ei = -1, bi = -1;
  for (int i = 0; i < N * 2; ++i)
    if (elsieHas[i])
      elsie[++ei] = i;
    else
      bessie[++bi] = i;

  ei = 0, bi = 0;
  int points = 0;
  while (ei < N && bi < N)
  {
    if (elsie[ei] < bessie[bi])
      ++points, ++ei, ++bi;
    else
      ++bi;
  }

  fout << points << '\n';

  return 0;
}
