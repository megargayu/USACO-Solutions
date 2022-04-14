#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  ofstream fout("paint.out");
  ifstream fin("paint.in");

  int a, b, c, d;
  fin >> a >> b >> c >> d;

  fout << b - a + d - c - max(min(b, d) - max(a, c), 0);

  return 0;
}
