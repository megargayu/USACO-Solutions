#include <bits/stdc++.h>
using namespace std;

#define MAX_N 50000 
#define MAX_NUM 1000000000

int N;
vector<int> bales(MAX_N);

bool checkRight(int x, int R)
{
  if (bales[N - 1] <= x + R) return true;

  for (int i = x, j = 0; i < bales[N - 1];)
  {
    for (; j + 1 < N && bales[j + 1] <= i + R; j++);
    if (bales[j] == i) return false;
    i = bales[j];
    R -= 2;
  }

  return true;
}

bool checkLeft(int x, int R)
{
  if (bales[0] >= x - R) return true;

  for (int i = x, j = N - 1; i > bales[0];)
  {
    for (; j - 1 >= 0 && bales[j - 1] >= i - R; j--);
    if (bales[j] == i) return false;
    i = bales[j];
    R -= 2;
  }

  return true;
}

bool tryR(int R)
{
  // find x
  int lo = bales[0], hi = bales[N - 1], x, ans;
  while (lo <= hi)
  {
    x = lo + (hi - lo) / 2;
    if (checkRight(x, R)) 
    {
      ans = x;
      hi = x - 1;
    } else lo = x + 1;
  }

  return checkLeft(ans, R);
}

int main()
{
  ifstream fin("angry.in");
  ofstream fout("angry.out");

  fin >> N;

  for (int i = 0; i < N; ++i)
    fin >> bales[i], bales[i] *= 2;

  sort(bales.begin(), bales.begin() + N);



  // find R
  int lo = 0, hi = MAX_NUM + 1, R, ans;
  while (lo <= hi)
  {
    R = lo + (hi - lo) / 2;
    if (tryR(R))
    {
      ans = R;
      hi = R - 1;
    } else lo = R + 1;
  }

  fout << ans / 2 << '.' << (ans % 2 ? '5' : '0') << '\n';

  return 0;
}