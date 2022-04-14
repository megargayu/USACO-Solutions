#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> ans;
int solve(ll curr, ll target)
{
  queue<pair<ll, vector<ll>>> q;
  q.push({curr, {0}});
  q.push({-1, {}}); // -1 at the end of each level

  int level = 0;
  while (!q.empty())
  {
    auto current = q.front();
    if (current.first == -1)
    {
      ++level;
      q.pop();
      q.push({-1, {}});
      if (q.front().first == -1) break;
      continue;
    }

    if (current.first == target)
    {
      cout << "FOUND\n";
      ans = current.second;
      ans.push_back(current.first);
      return level;
    }

    vector<ll> newV(current.second);
    newV.push_back(current.first);
    q.push({current.first + 1, newV});

    // don't multiply by 2 if you go further than target, because you 
    // then have to come back down by dividing by 2
    if (current.first * 2 <= target)
    {
      q.push({current.first * 2, newV});
    }

    if (current.first % 2 == 0 && current.first > 0)
    {
      q.push({current.first / 2, newV});
    }

    q.pop();
  }
  


  return false;
}

int main()
{
  int N;
  cin >> N;

  ll a, b;
  for (int i = 0; i < N; ++i)
  {
    cin >> a >> b;
    cout << solve(a, b) << '\n';
    for (int i = 0; i < ans.size(); ++i)
    {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
}
