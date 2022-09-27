// https://atcoder.jp/contests/dp/tasks/dp_a

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1e5

vector<int> h(MAX_N);

int cost(int i, int j)
{
  return abs(h[j] - h[i]);
}

int main()
{
  int N;
  cin >> N;

  for (int i = 0; i < N; ++i)
    cin >> h[i];

  if (N == 2)
  {
    cout << cost(0, 1) << '\n';
    return 0;
  }
  
  // n2 = min cost to go to stone n - 2 (starts at stone 1)
  // n1 = min cost to go to stone n - 1 (starts at stone 2)
  // n  = min cost to go to stone n     (starts at stone 3)
  int n2 = 0;
  int n1 = cost(0, 1);
  int n = min(n2 + cost(0, 2), n1 + cost(1, 2));

  for (int i = 3; i < N; ++i)
  {
    n2 = n1;
    n1 = n;
    n = min(n2 + cost(i - 2, i), n1 + cost(i - 1, i));
  }

  cout << n << '\n';
  return 0;
}
