#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

array<int, MAX_N> neighbors{1};
int main()
{
  int N;
  cin >> N;

  int a, b;
  for (int i = 0; i < N - 1; ++i)
  {
    cin >> a >> b;
    --a, --b;
    ++neighbors[a], ++neighbors[b];
  }

  int answer = N - 1;
  for (int i = 0; i < N; ++i)
  {
    int numCows = 1, times = 0;
    while (numCows < neighbors[i])
      numCows *= 2, ++times;
    answer += times;
  }

  cout << answer << '\n';

  return 0;
}
