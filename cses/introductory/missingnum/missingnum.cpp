// https://cses.fi/problemset/task/1083

#include <iostream>
#include <string>

using namespace std;

int main()
{
  long long n, x;
  cin >> n;

  long long sum = (n * (n + 1)) / 2;
  for (int i = 0; i < n - 1; ++i)
  {
    cin >> x;
    sum -= x;
  }

  cout << sum << '\n';

  return 0;
}
