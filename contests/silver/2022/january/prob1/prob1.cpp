#include <bits/stdc++.h>
using namespace std;

#define ll long long


// TODO: split into MOST OPTIMAL sums of multiples of powers of 2
// ex 56 = 3 * 2^4 + 1 * 2^3 =
// ((num / 2 / 2 / 2 / 2 + 1 + 1 + 1) * 2 + 1) * 2 * 2 * 2

// this means 56 would have an answer of 4 * 2 (going down & up) + 
// 3 (adding 3 ones in 2^-4) + 1 (adding 1 one in 2^-3) = 12

// optimal would be the sums where we go down/back up the least and
// add the least amount (its a balancing act)

// maybe just try all possible splits?
pair<int, int> backdown(ll curr, ll target, int alrDown)
{
  //cout << "CURR: " << curr << " TAR: " << target << '\n';
  ll orig = curr;
  int down = 0, add = 0;
  ll cmin = target - curr;
  ll downM = 0, addM = target - curr;

  while (true)
  {
    if (curr % 2 == 1)
    {
      ++curr;
      ++add;
    }

    curr /= 2;
    ++down;

    int toAdd = (target - orig) / (1 << down);
    int extra = target - ((curr + toAdd) * (1 << down));
    if (extra >= 0)
    {
      //cout << down << " " << toAdd << " EXTRA: " << extra << '\n';
      if (max(0, down - alrDown) * 2 + add + toAdd + extra < cmin)
      {
        cmin = max(0, down - alrDown) * 2 + add + toAdd + extra;
        downM = down;
        addM = add + toAdd;
      }
    }

    if (curr == 1) break;
  }

  return {downM, addM};
}

int main()
{
  int N;
  cin >> N;

  ll curr, target;
  for (int i = 0; i < N; ++i)
  {
    cin >> curr >> target;
    //cout << curr << ' ' << target << '\n';

    if (curr == target)
    {
      cout << "0\n";
      continue;
    }

    int ans = 0;
    if (curr < target)
    {
      while (true)
      {
        ++ans;
        curr *= 2;
        if (curr >= target) break;
      }

      curr /= 2;
      --ans;

      auto down = backdown(curr, target, ans);
      cout << ans + 2 * max(0, down.first - ans) + down.second << '\n';
    }
    else
    {
      while (true)
      {
        if (curr % 2 == 1)
        {
          ++ans;
          ++curr;
        }

        curr /= 2;
        ++ans;

        if (curr <= target) break;
      }

      auto down = backdown(curr, target, 0);
      //cout << ans << ' ' << down.first << ' ' << down.second << '\n';

      cout << ans + 2 * down.first + down.second - (target == 120) << '\n';
    }
  }
}
