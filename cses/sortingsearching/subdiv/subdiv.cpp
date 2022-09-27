// https://cses.fi/problemset/task/1662/

#include <iostream>
#include <string>

#include <map>

using namespace std;

map<int, int> numModSums{{0, 1}};
int main()
{
  int n;
  cin >> n;

  long answer = 0, prefixSum = 0, num;
  for (int i = 0; i < n; ++i)
  {
    cin >> num;
    prefixSum += num;
    int needToRemove = ((prefixSum % n) + n) % n;

    auto found = numModSums.find(needToRemove);
    if (found != numModSums.end())
    {
      answer += found->second;
      found->second += 1;
    }
    else
      numModSums.insert({needToRemove, 1});
  }

  cout << answer << '\n';

  return 0;
}
