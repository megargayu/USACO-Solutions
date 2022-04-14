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
// DONE!!!! :DDD

/*
997
+1  998 (1)
/2  499 (2)
+1  500 (3)
/2  250 (4)
/2  125 (5)
+1  126 (6)
/2   63 (7)
+1   64 (8)
/2   32 (9)
/2   16 (10)
/2    8 (11)
/2    4 (12)
+3    7 (15)
*2   14 (16)
+1   15 (17)
*2   30 (18)
*2   60 (19)
*2  120 (20)
*/

int leftover(ll curr, ll target, int alrUp)
{
  ll currDown = curr;
  ll down = 0, add = 0;

  ll ans = target - curr;
  while (currDown > 1)
  {
    if (currDown % 2 == 1) ++add, ++currDown;
    currDown /= 2, ++down;

    // go back up
    ll currUp = currDown;
    ll moreAdd = 0;
    for (int i = 0; i <= down; ++i)
    {
      ll currTarget = target / (1ll << (down - i));
      moreAdd += currTarget - currUp;
      currUp = currTarget * 2;
    }
    
    ans = min(ans, down * 2 - alrUp * 2 + add + moreAdd);
  }
  return ans;
}

int main()
{
  int N;
  cin >> N;

  ll curr, target;
  for (int i = 0; i < N; ++i)
  {
    cin >> curr >> target;

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

      cout << ans + leftover(curr, target, ans) << '\n';
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

      cout << ans + leftover(curr, target, 0) << '\n';
    }
  }
}
