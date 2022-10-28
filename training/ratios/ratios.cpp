/*
ID: megarga1
TASK: ratios
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

struct Mix
{
  int a, b, c;

  bool isMultipleOf(const Mix &o) const
  {
    const double ra = (double)a / o.a, rb = (double)b / o.b, rc = (double)c / o.c;
    if (ra < 1 || rb < 1 || rc < 1)
      return false;
      
    return !(a == 0 && b == 0 && c == 0) && !(isinf(ra) || isinf(rb) || isinf(rc)) && (ra == rb || (o.a == 0 || o.b == 0)) && (rb == rc || (o.b == 0 || o.c == 0));
  }
};

istream &operator>>(istream &in, Mix &m)
{
  in >> m.a >> m.b >> m.c;
  return in;
}

Mix operator*(const Mix &mix, int by)
{
  return {mix.a * by, mix.b * by, mix.c * by};
}

Mix operator+(const Mix &a, const Mix &b)
{
  return {a.a + b.a, a.b + b.b, a.c + b.c};
}

int main()
{
  ifstream fin("ratios.in");
  ofstream fout("ratios.out");

  Mix goal, a, b, c;
  fin >> goal >> a >> b >> c;

  int aa = 1000, ab = 1000, ac = 1000;
  for (int i = 0; i <= 100; ++i)
    for (int j = 0; j <= 100; ++j)
      for (int k = 0; k <= 100; ++k)
      {
        const Mix mixture = a * i + b * j + c * k;
        if (mixture.isMultipleOf(goal) && i + j + k < aa + ab + ac)
          aa = i, ab = j, ac = k;
      }

  if (aa == 1000)
    fout << "NONE\n";
  else
    fout << aa << ' ' << ab << ' ' << ac << ' ' << (aa * a.a + ab * b.a + ac * c.a) / goal.a << '\n';

  return 0;
}
