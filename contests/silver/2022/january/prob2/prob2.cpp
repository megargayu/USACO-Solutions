#include <bits/stdc++.h>
using namespace std;

vector<int> in(3e5);
int main()
{
  int N;
  cin >> N;

  cin >> in[0];
  long long answer = 0;
  for (int j = 1; j < N; ++j)
  {
    cin >> in[j];

    int cmax = -1;
    for (int i = j - 1; i >= 0; --i)
    {
      if (min(in[i], in[j]) > cmax || cmax == -1)
      {
        answer += j - i + 1;
      }
      cmax = max(cmax, in[i]);
    }
  }

  cout << answer << '\n';
}