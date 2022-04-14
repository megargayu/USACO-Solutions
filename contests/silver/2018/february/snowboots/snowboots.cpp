#include <bits/stdc++.h>
using namespace std;

#define MAX 250
#define ll long long

struct Boot
{
  ll depth;
  int step;
};

array<ll, MAX> snow;
array<Boot, MAX> boots;
array<array<bool, MAX>, MAX> states;
int N, B, best = MAX + 1;

void recurse(int loc, int boot)
{
  if (states[loc][boot]) return;
  states[loc][boot] = true;

  // at end
  if (loc == N - 1) 
  {
    best = min(best, boot);
    return;
  }

  // try all possible new locations that can be gone to with this boot
  for (int newLoc = loc + 1; newLoc < min(loc + 1 + boots[boot].step, N); ++newLoc)
    if (snow[newLoc] <= boots[boot].depth) recurse(newLoc, boot);
  
  // discard boot
  for (int newBoot = boot + 1; newBoot < B; ++newBoot)
    if (snow[loc] <= boots[newBoot].depth)
    {
      recurse(loc, newBoot);
      break;
    }
}

int main()
{
  ifstream fin("snowboots.in");
  ofstream fout("snowboots.out");

  fin >> N >> B;
  for (int i = 0; i < N; ++i) fin >> snow[i];
  for (int i = 0; i < B; ++i) fin >> boots[i].depth >> boots[i].step;

  // brute force!
  recurse(0, 0);
  fout << best << '\n';

  return 0;
}
