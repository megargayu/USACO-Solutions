#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// https://codeforces.com/problemset/problem/1359/C

double bestK(double h, double c, double t)
{
  return (t - h) / (h + c - 2 * t);
}

double tOfK(double h, double c, long long k)
{
  return (h * (k + 1) + c * k) / (2 * k + 1);
}

int main()
{
  int T;
  cin >> T;

  double h, c, t;
  for (int i{0}; i < T; ++i)
  {
    cin >> h >> c >> t;
    if (t <= (h + c) / 2.0)
    {
      cout << "2\n";
      continue;
    }

    long long k{static_cast<long long>(floor(bestK(h, c, t)))};
    double tFloorDist{abs(tOfK(h, c, k) - t)}, tCeilDist{abs(tOfK(h, c, k + 1) - t)};

    if (tFloorDist == tCeilDist || tFloorDist < tCeilDist)
      cout << to_string(2 * k + 1) << '\n';
    else
      cout << to_string(2 * k + 3) << '\n';
  }

  return 0;
}
