/*
ID: megarga1
TASK: ride
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  ofstream fout("ride.out");
  ifstream fin("ride.in");

  std::string s1, s2;
  fin >> s1 >> s2;

  int s1val{1}, s2val{1};
  for (char c : s1)
    s1val = s1val * (c - 'A' + 1) % 47;

  for (char c : s2)
    s2val = s2val * (c - 'A' + 1) % 47;

  fout << (s1val == s2val ? "GO" : "STAY") << '\n';

  return 0;
}