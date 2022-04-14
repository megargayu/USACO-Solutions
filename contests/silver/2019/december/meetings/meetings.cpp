#include <bits/stdc++.h>
using namespace std;

#define MAX_N 50000

struct Cow
{
  int w, x;
  bool operator<(const Cow& o) { return x < o.x; }
};

vector<Cow> leftC, rightC;
int main()
{
  ifstream fin("meetings.in");
  ofstream fout("meetings.out");

  int N, L;
  fin >> N >> L;

  int w, x, d;
  for (int i = 0; i < N; ++i) 
  {
    cin >> w >> x >> d;
    if (d == -1) leftC.push_back({ w, x });
    else rightC.push_back({ w, x });
  }
  
  sort(leftC.begin(), leftC.end());
  sort(rightC.begin(), rightC.end());

  // find T
  int i, j, T;
  

  return 0;
}
