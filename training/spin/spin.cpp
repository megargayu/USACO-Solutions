/*
ID: megarga1
TASK: spin
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

#include <vector>
#include <array>
#include <bitset>
#include <limits>

using namespace std;

array<int, 5> rotSpeed{};
array<bitset<360>, 5> wheels{};

void wrapShiftLeft(bitset<360> &bits, int amount)
{
  vector<bool> lastBits(amount);
  for (int i{0}; i < amount; ++i)
    lastBits[i] = bits.test(360 - amount + i);

  bits <<= amount;

  for (int i{0}; i < amount; ++i)
    bits.set(i, lastBits[i]);
}

int main()
{
  ofstream fout("spin.out");
  ifstream fin("spin.in");

  int W;
  for (int i{0}; i < 5; ++i)
  {
    fin >> rotSpeed[i] >> W;
    for (int j{0}; j < W; ++j)
    {
      int start, extent;
      fin >> start >> extent;
      int curr{start};
      for (int k{0}; k <= extent; ++k)
      {
        wheels[i].set(curr);
        curr = (curr + 1) % 360;
      }
    }
  }

  for (int i{0}; i < 360; ++i)
  {
    if ((wheels[0] & wheels[1] & wheels[2] & wheels[3] & wheels[4]).any())
    {
      fout << i << '\n';
      return 0;
    }

    for (int j{0}; j < 5; ++j)
      wrapShiftLeft(wheels[j], rotSpeed[j]);
  }

  fout << "none\n";

  return 0;
}
