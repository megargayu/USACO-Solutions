// https://cses.fi/problemset/task/1093

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 500;
const int MAX_SUM = MAX_N * (MAX_N + 1) / 2;
const int MOD = 1e9 + 7;

vector<int> last(MAX_SUM + 1, 0), curr(MAX_SUM + 1, 0);

int main()
{
  int n;
  cin >> n;

  const int sum = (n * (n + 1)) / 2;
  if (sum % 2 == 1)
  {
    cout << "0\n";
    return 0;
  }

  const int target = sum / 2;

  last[0] = 1;
  curr[0] = 1;
  for (int num = 1; num < n; ++num)
  {
    for (int i = 0; i <= target; ++i)
    {
      if (i - num >= 0)
        curr[i] += last[i - num];

      curr[i] %= MOD;
    }

    last = curr;
  }

  cout << curr[target] << '\n';

  return 0;
}