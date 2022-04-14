// https://oj.uz/problem/view/IOI10_traffic
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX_N 1000000
#define INF 2e9

vector<ll> sum(MAX_N);
vector<int> parent(MAX_N);
vector<vector<int>> adj(MAX_N);
ll maxSum = 0;

void dfs(int par, int cur)
{
  for (const int &w : adj[cur])
    if (w != par)
    {
      parent[w] = cur;
      dfs(cur, w);
      sum[cur] += sum[w];
    }
}

int LocateCentre(int N, int P[], int S[], int D[])
{
  for (int i = 0; i < N; ++i)
  {
    sum[i] = P[i];
    maxSum += P[i];
  }

  for (int i = 0; i < N - 1; ++i)
  {
    adj[S[i]].push_back(D[i]);
    adj[D[i]].push_back(S[i]);
  }

  dfs(0, 0);

  ll minOut = INF, minI = INF;
  for (int i = 0; i < N; ++i)
  {
    ll maxOut = maxSum - sum[i];
    for (const int &w : adj[i])
      if (w != parent[i]) // don't check parent -> child relationship, because 
        maxOut = max(maxOut, sum[w]); // that is calculated differently

    if (maxOut < minOut)
    {
      minOut = maxOut;
      minI = i;
    }
  }
  
  return minI;
}

// testing (do not submit to grader)
int main()
{
  int fans[] { 10, 10, 10, 20, 20 };
  int adj0[] { 0, 1, 2, 3 };
  int adj1[] { 2, 2, 3, 4 };

  int ans = LocateCentre(5, fans, adj0, adj1);
  cout << "\n\nANS: " << ans << '\n';
}
