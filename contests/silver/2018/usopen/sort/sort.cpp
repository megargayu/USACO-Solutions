#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1e5
#define pii pair<int, int>

vector<pii> A(MAX_N);

int main()
{
  ifstream fin("sort.in");
  ofstream fout("sort.out");

  int N;
  fin >> N;

  for (int i = 0; i < N; ++i)
  {
    fin >> A[i].first;
    A[i].second = i;
  }

  sort(A.begin(), A.begin() + N, [](const pii &a, const pii &b)
       { return a.first == b.first ? a.second < b.second : a.first < b.first; });

  int ans = 0;
  for (int i = 0; i < N; ++i)
    ans = max(ans, A[i].second - i);

  fout << ans + 1 << '\n';

  return 0;
}
