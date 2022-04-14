// https://cses.fi/problemset/task/1643

#include <iostream>
#include <string>

#include <unordered_set>

using namespace std;

int main()
{
  int n, x;
  cin >> n >> x;

  unordered_multiset<long long> prevNums{0};
  prevNums.reserve(n);
  long long num, prefix{0}, ans{0};
  for (int i{0}; i < n; ++i)
  {
    cin >> num;
    prefix += num;
    ans += prevNums.count(prefix - x);
    prevNums.insert(prefix);
  }

  cout << ans << '\n';

  return 0;
}
