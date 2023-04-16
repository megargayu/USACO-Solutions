#include <bits/stdc++.h>
using namespace std;

int main()
{
  int T;
  cin >> T;

  int x, y;
  while (T--)
  { 
    cin >> x >> y;
    cout << "2\n" << x - 1 << " 1\n" << x << ' ' << y << '\n';
  }
}
