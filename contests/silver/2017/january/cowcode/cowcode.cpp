#include <bits/stdc++.h>
using namespace std;

#define ll long long

string s;
ll N;

ll size(int x)
{
  return (1LL << x) * s.size();
}

char f(int x, ll i)
{
  if (x == 0) return s[i];
  if (i < size(x - 1)) return f(x - 1, i);

  ll half = size(x - 1); i -= half;
  if (i == 0) return f(x - 1, half - 1);
  return f(x - 1, i - 1);
}

int main()
{
  ifstream fin("cowcode.in");
  ofstream fout("cowcode.out");

  fin >> s >> N;
  
  int x = max(0, (int)ceil(log2((double)N / s.size())));
  fout << f(x, N - 1) << '\n';

  return 0;
}
