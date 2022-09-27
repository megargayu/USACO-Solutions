// https://cses.fi/problemset/task/1650

#include <iostream>
#include <string>
#include <array>

using namespace std;

#define MAX_N 200000

array<int, MAX_N + 1> prefixSums{};

int main()
{
  int N, Q;
  cin >> N >> Q;

  cin >> prefixSums[1];
  for (int i{2}; i <= N; ++i)
  {
    int num;
    cin >> num;
    prefixSums[i] = prefixSums[i - 1] ^ num;
  }

  for (int i{0}; i < Q; ++i)
  {
    int a, b;
    cin >> a >> b;
    cout << (prefixSums[a - 1] ^ prefixSums[b]) << '\n';
  }

  return 0;
}
