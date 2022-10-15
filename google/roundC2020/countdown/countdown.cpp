// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/00000000003380d2

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int T;
  cin >> T;

  int N, K, a;
  int seenSoFar, ans;
  for (int t = 1; t <= T; ++t)
  {
    cin >> N >> K;

    seenSoFar = 0, ans = 0;
    for (int i = 0; i < N; ++i)
    {
      cin >> a;
      if (seenSoFar == K)
      {
        ++ans;
        seenSoFar = 0;
      }
      
      if (a == K - seenSoFar)
        ++seenSoFar;
      else
        seenSoFar = a == K;
    }

    cout << "Case #" << t << ": " << ans + (seenSoFar == K) << '\n';
  }

  return 0;
}