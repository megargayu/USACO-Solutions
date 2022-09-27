// https://cses.fi/problemset/task/1643/

#include <iostream>
#include <string>

using namespace std;

int main()
{
  int n;
  cin >> n;

  long prefixSum = 0, minPrefixSum = 0, num;
  cin >> num;
  long answer = num;
  for (int i = 0; i < n; ++i)
  {
    prefixSum += num;
    answer = max(answer, prefixSum - minPrefixSum);
    minPrefixSum = min(prefixSum, minPrefixSum);
    if (i + 1 < n)
      cin >> num;
  }

  cout << answer << '\n';

  return 0;
}
