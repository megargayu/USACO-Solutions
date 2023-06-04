// https://codeforces.com/problemset/problem/1791/G2

// DOES NOT WORK because it doesn't check each starting portal

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 2e5

int N, C;
vector<int> iToL(MAX_N), iToR(MAX_N);
multiset<pair<int, int>> fromL, fromR;

int solve()
{
  if (fromL.begin()->first > C)
    return 0;

  // we cannot check from the minimum portal!! must go over every possible startng portal and check from there
  int money = fromL.begin()->first, ans = 0;
  fromR.erase({iToR[fromL.begin()->second], fromL.begin()->second});
  fromL.erase(fromL.begin());
  ++ans;

  while (true)
  {
    int pL = money + fromL.begin()->first, pR = money + fromR.begin()->first;
    
    if (pL > C && pR > C)
      break;
    
    if (pL < pR)
    {
      // go to 0 and take the least element from the left
      money = pL;
      fromR.erase({iToR[fromL.begin()->second], fromL.begin()->second});
      fromL.erase(fromL.begin());
      cout << "used teleporter (left) " << fromL.begin()->first << ' ' << fromL.begin()->second << '\n';
    }
    else
    {
      // go to N + 1 and take the least element from the right
      money = pR;
      fromL.erase({iToL[fromR.begin()->second], fromR.begin()->second});
      fromR.erase(fromR.begin());
      cout << "used teleporter (right) " << fromR.begin()->first << ' ' << fromR.begin()->second << '\n';
    }


    ++ans;
  }

  return ans;
}

int main()
{
  int T;
  cin >> T;

  int a;
  for (int i = 0; i < T; ++i)
  {
    cin >> N >> C;

    fromL.clear();
    fromR.clear();
    for (int i = 0; i < N; ++i)
    {
      cin >> a;
      iToL[i] = i + 1 + a;
      iToR[i] = N - i + a;
      fromL.emplace(iToL[i], i); // 1 + a, 2 + a...
      fromR.emplace(iToR[i], i); // 5 + a, 4 + a...
    }

    cout << solve() << '\n';
  }

  return 0;
}