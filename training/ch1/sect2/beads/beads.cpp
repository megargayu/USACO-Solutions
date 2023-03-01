/*
ID: megarga1
TASK: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  ofstream fout("beads.out");
  ifstream fin("beads.in");

  int N;
  fin >> N;

  string necklace;
  fin >> necklace;

  // The current color of the bead (null if white or not initialized)
  char curr{'\0'};

  // The start of the current subsequence
  int start{0};

  // The last "w" that the next subsequence can start from (if any)
  int lastW{-1};
  int overlap{0}; // The overlap between the previous subsequence's end and the current subsequence's start

  // The previous subsequence's length (left side of split)
  int last{0};

  int ans{0};
  int i{0};
  for (;; ++i)
  {
    int wrapped{i % N};
    if (i >= N && wrapped == start)
      break;

    if (curr != '\0' && necklace[wrapped] != 'w' && necklace[wrapped] != curr)
    {
      if (i >= N)
        break;

      if (last != 0)
        ans = max(ans, last + (i - start) - overlap);

      last = i - start;

      curr = '\0';
      start = wrapped;
      overlap = 0;

      if (lastW != -1)
      {
        i = lastW;
        start = lastW;
        overlap = wrapped - lastW;
      }
    }

    if (curr == '\0' && necklace[wrapped] != 'w')
      curr = necklace[wrapped];

    if (necklace[wrapped] == 'w')
      lastW = wrapped;
    else
      lastW = -1;
  }

  ans = max(ans, last + (i - start) - overlap);

  fout << ans << '\n';

  return 0;
}
