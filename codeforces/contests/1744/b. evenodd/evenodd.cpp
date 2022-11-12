// https://codeforces.com/contest/1744/problem/B

#include <bits/stdc++.h>
using namespace std;

#define MAX 1e5
#define ll long long

int n, q;
vector<ll> a(MAX);

void solve()
{
  ll sum = 0;
  int odd = 0, even = 0;
  for (int i = 0; i < n; ++i)
  {
    sum += a[i];
    if (a[i] % 2 == 0)
      ++even;
    else
      ++odd;
  }

  bool isOdd;
  int x;
  for (int i = 0; i < q; ++i)
  {
    cin >> isOdd >> x;
    if (isOdd)
    {
      sum += odd * x;
      if (x % 2 == 1)
      {
        even += odd;
        odd = 0;
      }
    }
    else
    {
      sum += even * x;
      if (x % 2 == 1)
      {
        odd += even;
        even = 0;
      }
    }
    cout << sum << '\n';
  }
}

int main()
{
  int t;
  cin >> t;

  for (int test = 0; test < t; ++test)
  {
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    solve();
  }
}