// https://cses.fi/problemset/task/1163

#include <iostream>
#include <string>

#include <set>

using namespace std;

int main()
{
  int x, n;
  cin >> x >> n;

  multiset<int> passages{x};
  set<int> points{0, x};
  int num;
  for (int i{0}; i < n; ++i)
  {
    cin >> num;
    auto right{points.upper_bound(num)}, left{right};
    --left; // num must be greater than 0, so there is always something before

    passages.erase(passages.find(*right - *left));
    passages.insert(num - *left);
    passages.insert(*right - num);

    points.insert(num);

    auto end{passages.end()};
    cout << *(--end) << ' ';
  }

  cout << '\n';

  return 0;
}
