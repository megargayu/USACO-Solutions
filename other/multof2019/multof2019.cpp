#include <bits/stdc++.h>
using namespace std;

#define MAX_N 200000
#define ll long long

vector<int> cnt(2019, 0);

int main()
{
  string s;
  cin >> s;

  int num = 0, power = 1;
  cnt[0] = 1;
  for (int i = s.size() - 1; i >= 0; --i)
  {
    num = (num + power * (s[i] - '0')) % 2019;
    ++cnt[num];
    power = (power * 10) % 2019;
  }

  ll ans = 0;
  for (int i = 0; i < 2019; ++i)
    ans += static_cast<ll>(cnt[i]) * (cnt[i] - 1) / 2;
  
  cout << ans << '\n';

  return 0;  
}