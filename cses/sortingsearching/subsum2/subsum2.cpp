// https://cses.fi/problemset/task/1661/

#include <iostream>
#include <string>

#include <map>

using namespace std;

map<long, int> prevPrefixSums{{0, 1}};

int main()
{
  int n, x;
  cin >> n >> x;

  long prefixSum = 0, num, answer = 0;
  for (int i = 0; i < n; ++i)
  {
    cin >> num;
    prefixSum += num;
    auto found = prevPrefixSums.find(prefixSum - x);
    if (found != prevPrefixSums.end())
      answer += found->second;

    found = prevPrefixSums.find(prefixSum);
    if (found == prevPrefixSums.end())
      prevPrefixSums.insert({prefixSum, 1});
    else
      found->second += 1;
  }

  cout << answer << '\n';

  return 0;
}
