#include <bits/stdc++.h>
using namespace std;

bool type1(int x)
{
  cout << "+ " << x << endl;
  
  int result;
  cin >> result;

  return result == 1;
}

int type2(int i, int j)
{
  cout << "? " << i + 1 << ' ' << j + 1 << endl;

  int result;
  cin >> result;

  return result;
}

bool solve()
{
  int n;
  cin >> n;

  if (!type1(n + 1)) return false;
  if (!type1(n + 2)) return false;

  vector<int> diffs(n);
  diffs[0] = 0;

  int currMaxI = 0;
  for (int i = 1; i < n; ++i)
  {
    diffs[i] = type2(0, i);
    if (diffs[i] == -2) return false;

    if (diffs[i] > diffs[currMaxI])
      currMaxI = i;
  }

  // currMaxI is an endpoint
  vector<int> enddiffs(n);
  enddiffs[currMaxI] = 0;
  
  for (int i = 0; i < n; ++i)
  {
    if (i == currMaxI) continue;

    enddiffs[i] = type2(currMaxI, i);
    if (enddiffs[i] == -2) return false;
  }

  // maps distance -> value (assuming currMaxI = 1, as 1 is always an endpoint)
  vector<int> value(n);
  
  for (int i = 0; i < n; i += 2)
    value[i] = i / 2 + 1;

  for (int i = 1; i < n; i += 2)
    value[i] = n - i / 2;

  // output answer
  cout << "! ";

  // assume 1 is the endpoint
  for (int i = 0; i < n; ++i)
    cout << value[enddiffs[i]] << ' ';
  
  // assume currMaxI is the endpoint
  for (int i = 0; i < n - 1; ++i)
    cout << value[n - enddiffs[i] - 1] << ' ';

  cout << value[n - enddiffs[n - 1] - 1] << endl;

  int result;
  cin >> result;
  
  return result == 1;
}

int main()
{
  int T;
  cin >> T;

  while (T--)
    if (!solve())
      return 1;

  return 0;
}
