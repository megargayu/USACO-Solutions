#include <string>
#include <fstream>
#include <cmath>

// the numbers are so large that we have to use long longs (64-bit integers)
using ll = long long;

// note that "s" is now global instead of being passed through each function
// (this just makes it easier)
std::string s;
ll N;

ll size(int n)
{
  // 1LL << x is the same thing as 2^x. Why? Because of bits, of course.
  return (1LL << n) * s.size();
}

char f(int n, ll i)
{
  // first condition - we can just return to make the rest of the code cleaner
  if (n == 0)
    return s[i];

  // second condition (first part of string)
  if (i < size(n - 1))
    return f(n - 1, i);

  // everything else has been subtracted by the previous iteration value,
  // just to make our lives easier - the math is still the exact same.
  ll half = size(n - 1);
  i -= half;

  // third condition (second part of string)
  if (i == 0)
    return f(n - 1, half - 1);

  // fourth condition (third part of string)
  return f(n - 1, i - 1);
}

int main()
{
  std::ifstream fin("cowcode.in");
  std::ofstream fout("cowcode.out");

  fin >> s >> N;

  // this is the same as the equation given, it's just more complicated
  // because of the static_casts to make sure C++ converts the numbers into
  // their correct forms.
  int n = std::max(0, static_cast<int>(std::ceil(std::log2(static_cast<double>(N) / s.size()))));

  // we pass N - 1 as everything is 0-indexed in this code
  fout << f(n, N - 1) << '\n';

  return 0;
}
