// https://codeforces.com/contest/1744/problem/A

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1e5

int n;
vector<int> a(MAX_N);
vector<char> cmap(51);
string s;

bool solve()
{
  fill(cmap.begin(), cmap.end(), '\0');
  for (int i = 0; i < n; ++i)
  {
    if (cmap[a[i]] == '\0')
      cmap[a[i]] = s[i];
    else if (s[i] != cmap[a[i]])
      return false;
  }
  return true;
}

int main()
{
  int t;
  cin >> t;

  for (int test = 0; test < t; ++test)
  {
    cin >> n;
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    cin >> s;
    
    cout << (solve() ? "YES" : "NO") << '\n';
  }


  return 0;
}