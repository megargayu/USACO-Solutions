// https://cses.fi/problemset/task/1094

#include <iostream>
#include <string>

using namespace std;

int main()
{
  int n;
  cin >> n;

  long lastNum, moves = 0, num;
  cin >> lastNum;

  for (int i = 1; i < n; ++i)
  {
    cin >> num;
    if (num < lastNum)
      moves += lastNum - num;
    else
      lastNum = num;
  }

  cout << moves << '\n';

  return 0;
}
