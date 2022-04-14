// https://codeforces.com/problemset/problem/1000/C

#include <iostream>
#include <string>

#include <set>
#include <array>

#define MAX_N 200000

using namespace std;

bool cmp(const pair<long long, bool> &a, const pair<long long, bool> &b)
{
  // If the POI are the same, the one that is true (if any/both) is first
  if (a.first == b.first)
    return a.second;
  return a.first < b.first;
}

array<long long, MAX_N> count{};
multiset<pair<long long, bool>, decltype(&cmp)> POI(&cmp);

int main()
{
  int n;
  cin >> n;

  long long a, b;
  for (int i{0}; i < n; ++i)
  {
    cin >> a >> b;
    POI.insert({a, true});
    POI.insert({b, false});
  }

  int curr{0};
  pair<long long, bool> lastPoint{*POI.begin()};
  bool isFirst{true};
  for (const auto &point : POI)
  {
    // Skip first point, it will always be a start
    if (isFirst)
    {
      isFirst = false;
      continue;
    }

    count[curr] += point.first - lastPoint.first + (lastPoint.second && !point.second) - (!lastPoint.second && point.second);
    if (point.second)
      ++curr;
    else
      --curr;

    lastPoint = point;
  }

  for (int i{0}; i < n; ++i)
    cout << count[i] << ' ';
  cout << '\n';

  return 0;
}
