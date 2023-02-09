#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1e5

// between the i-th and i + 1-th tiles
vector<int> a(MAX_N);

int i;
string ans = "";

void right()
{
  ans += 'R';
  --a[i];
  ++i;
}

void left()
{
  ans += 'L';
  --i;
  --a[i];
}

int main()
{
  int N;
  cin >> N;

  for (int i = 0; i < N; ++i)
  {
    cin >> a[i];
    assert(a[i] % 2 == 0); // assume all values are even..
  }
  
  i = 0;
  bool dir = true; // true = right, false = left
  while (!(i == N && a[i - 1] == 1))
  {
    // go right
    if (dir == true)
    {
      // if a[i - 1] == 1, we know that everything before this tile has been completed
      if (i < N && (a[i] != 2 || (a[i] == 2 && (i == 0 || a[i - 1] == 1))))
        right();
      // Cannot go past this point!
      else
      {
        dir = false;
        left();
      }
    }
    // go left
    else
    {
      if (i > 0 && a[i - 1] != 1)
        left();
      // everything including and before i - 1 has been completed; we can only go back once the entire thing has been solved
      else
      {
        dir = true;
        right();
      }
    }
  }

  while (i > 0)
  {
    ans += 'L';
    --i;
  }

  cout << ans << '\n';

  return 0;
}