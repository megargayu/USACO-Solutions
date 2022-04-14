// https://cses.fi/problemset/task/1640

#include <iostream>
#include <string>

#include <unordered_set>

using namespace std;

class pair_hash
{
public:
  size_t operator()(pair<int, int> const &pair) const
  {
    return hash<int>()(pair.first);
  }
};

int main()
{
  int n, x;
  cin >> n >> x;

  unordered_set<pair<int, int>, pair_hash> prevNums{};
  prevNums.reserve(n);
  int num;
  for (int i{0}; i < n; ++i)
  {
    cin >> num;
    auto found{prevNums.find({x - num, 0})};
    if (found != prevNums.end())
    {
      cout << found->second << ' ' << i << '\n';
      return 0;
    }
    prevNums.insert({num, i});
  }

  return 0;
}
