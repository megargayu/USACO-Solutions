// submitted to https://www.spoj.com/problems/HAYBALE/

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000000

vector<int> haybales(MAX_N + 5, 0);

int main()
{
  //ifstream fin("stacking.in");
  //ofstream fout("stacking.out");

  int N, K;
  cin >> N >> K;

  int a, b;
  for (int i = 0; i < K; ++i)
  {
    cin >> a >> b;
    --a, --b;
    ++haybales[a];
    --haybales[b + 1];
  }

  for (int i = 1; i < N; ++i)
  {
    haybales[i] += haybales[i - 1];
  }

  sort(haybales.begin(), haybales.begin() + N);

  cout << haybales[N / 2] << '\n';

  return 0;
}