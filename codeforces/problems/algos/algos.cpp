// https://codeforces.com/gym/102951/problem/B

#include <iostream>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

#define MAX_N 100

array<int, MAX_N> algos{};

int main()
{
  int N, X;
  cin >> N >> X;

  for (int i{0}; i < N; ++i)
    cin >> algos[i];

  sort(algos.begin(), algos.begin() + N);

  int ans{0};
  for (; ans < N && X - algos[ans] >= 0; ++ans)
    X -= algos[ans];

  cout << ans << '\n';

  return 0;
}
