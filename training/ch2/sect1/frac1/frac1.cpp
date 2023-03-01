/*
ID: megarga1
TASK: frac1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

// USACO Training grader is not C++17 compatible :(
int gcd(int a, int b)
{
  return b == 0 ? a : gcd(b, a % b);
}

class Fraction
{
public:
  int numerator;
  int denominator;

  Fraction(int num, int den)
  {
    this->numerator = num;
    this->denominator = den;

    simplify();
  }

  void simplify()
  {
    int fracGCD{gcd(this->numerator, this->denominator)};
    this->numerator /= fracGCD;
    this->denominator /= fracGCD;
  }

  friend bool operator==(const Fraction &lhs, const Fraction &rhs)
  {
    return lhs.numerator == rhs.numerator && lhs.denominator == rhs.denominator;
  }

  friend bool operator<(const Fraction &lhs, const Fraction &rhs)
  {
    return static_cast<double>(lhs.numerator) /
               static_cast<double>(lhs.denominator) <
           static_cast<double>(rhs.numerator) /
               static_cast<double>(rhs.denominator);
  }

  friend ostream &operator<<(ostream &out, const Fraction &fraction)
  {
    out << fraction.numerator << '/' << fraction.denominator;

    return out;
  }
};

int main()
{
  ofstream fout("frac1.out");
  ifstream fin("frac1.in");

  int N;
  fin >> N;
  fin.close();

  set<Fraction> fractions;

  for (int den{2}; den <= N; ++den)
    for (int num{1}; num <= den - 1; ++num)
      fractions.insert({num, den});

  fout << "0/1\n";
  for (Fraction frac : fractions)
    fout << frac << '\n';
  fout << "1/1\n";

  fout.close();

  return 0;
}
