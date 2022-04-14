#include <bits/stdc++.h>
using namespace std;

#define MAX 200000
#define ll long long

// location, tastiness - tastiness is -1 if cow
vector<pair<ll, ll>> farm(MAX * 2);
vector<ll> possTastiness;
int main()
{
  int K, M, N;
  cin >> K >> M >> N;

  int farmI = 0;
  for (int i = 0; i < K; ++i, ++farmI)
    cin >> farm[farmI].first >> farm[farmI].second;

  for (int i = 0; i < M; ++i, ++farmI)
  {
    cin >> farm[farmI].first;
    farm[farmI].second = -1;
  }

  sort(farm.begin(), farm.begin() + K + M, [](const auto &a, const auto &b)
  { return a.first < b.first; });

  int lastI = -1;
  ll sum = 0;
  for (int i = 0; i < K + M; ++i)
  {
    if (farm[i].second == -1)
    {
      if (lastI == -1) possTastiness.push_back(sum);
      else
      {
        ll currSum = 0, maxSum = 0;
        ll windowDist = (farm[i].first - farm[lastI].first) / 2;
        for (int l = lastI + 1, r = lastI; l < i; ++l)
        {
          while (r + 1 < i && farm[r + 1].first - farm[l].first < windowDist)
          {
            currSum += farm[++r].second;
          }

          maxSum = max(maxSum, currSum);
          currSum -= farm[l].second;
        }

        possTastiness.push_back(maxSum);
        possTastiness.push_back(sum - maxSum);
      }

      lastI = i;
      sum = 0;
    }
    else
    {
      sum += farm[i].second;
    }
  }

  // last cow
  possTastiness.push_back(sum);

  sort(possTastiness.rbegin(), possTastiness.rend());

  ll ans = 0;
  for (int i = 0; i < N; ++i)
    ans += possTastiness[i];

  cout << ans << '\n';

  return 0;
}
