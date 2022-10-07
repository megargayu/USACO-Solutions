// https://cses.fi/problemset/task/1188

#include <bits/stdc++.h>
using namespace std;

int n;
set<int> starts;
multiset<int> lengths;

void update(int x)
{
  if (x == 0 || x == n) return;

  auto found = starts.find(x);
  if (found != starts.end()) // this start exists already, remove it
  {
    int left = *prev(found), right = *next(found);

    lengths.erase(lengths.find(right - x));
    lengths.erase(lengths.find(x - left));
    
    lengths.insert(right - left);

    starts.erase(found);
  }
  else // this start doesn't exist, add it
  {
    found = starts.insert(x).first;

    int left = *prev(found), right = *next(found);

    lengths.erase(lengths.find(right - left));

    lengths.insert(x - left);
    lengths.insert(right - x);
  }
}

int main()
{
  string s;
  cin >> s;

  n = s.size();

  // prevent iterator out of bounds
  starts.insert(0);
  starts.insert(n);

  // generate components
  int start = 0;
  for (int i = 1; i <= n; ++i)
    if (i == n || s[i] != s[start])
    {
      starts.insert(i);
      lengths.insert(i - start);
      start = i;
    }

  int m;
  cin >> m;

  int x;
  for (int i = 0; i < m; ++i)
  {
    cin >> x;
    --x;

    update(x);
    update(x + 1);

    cout << *lengths.rbegin() << ' ';
  }

  cout << '\n';

  return 0;
}

// TODO