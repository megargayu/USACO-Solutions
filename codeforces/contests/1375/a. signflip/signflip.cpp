#include <bits/stdc++.h>
using namespace std;

#define MAX_N 99

vector<int> nums(MAX_N);
int N;

int main()
{
  int T;
  cin >> T;

  for (int t = 0; t < T; ++t)
  {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> nums[i];

    for (int i = 0; i < N; ++i)
    {
      if (i % 2 == 0) nums[i] = -abs(nums[i]);
      else nums[i] = abs(nums[i]);

      cout << nums[i];
      if (i < N - 1) cout << ' ';
    }
    cout << '\n';
  }

  return 0;
}
