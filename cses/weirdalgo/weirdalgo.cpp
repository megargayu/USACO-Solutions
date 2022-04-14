// https://cses.fi/problemset/task/1068/

#include <iostream>
#include <string>

using namespace std;

int main()
{
  long n;
  cin >> n;

  while (n > 1)
  {
    cout << n << ' ';
    if (n % 2 == 0)
      n /= 2;
    else
      n = n * 3 + 1;
  }

  cout << "1\n";

  return 0;
}