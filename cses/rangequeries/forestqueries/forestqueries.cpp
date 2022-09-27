// https://cses.fi/problemset/task/1652/

#include <iostream>
#include <string>

#include <array>

using namespace std;

#define MAX_SIDE 1000

array<array<int, MAX_SIDE + 1>, MAX_SIDE + 1> prefix;
int main()
{
  int N, Q;
  int i, j, x1, y1, x2, y2;
  char tree;

  cin >> N >> Q;
  for (i = 1; i <= N; ++i)
    for (j = 1; j <= N; ++j)
    {
      cin >> tree;
      prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + (tree == '*');
    }

  for (i = 0; i < Q; ++i)
  {
    cin >> y1 >> x1 >> y2 >> x2;
    cout << prefix[y2][x2] - prefix[y1 - 1][x2] - prefix[y2][x1 - 1] + prefix[y1 - 1][x1 - 1] << '\n';
  }

  return 0;
}
