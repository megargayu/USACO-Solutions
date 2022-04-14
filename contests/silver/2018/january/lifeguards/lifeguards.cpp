#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000
#define ll long long

struct point
{
  ll time;
  bool start;
  int intervalNum;
};

array<point, MAX_N * 2> POI;
int main()
{
  ifstream fin("lifeguards.in");
  ofstream fout("lifeguards.out");

  int N;
  fin >> N;

  for (int i = 0; i < N; ++i)
  {
    fin >> POI[i * 2].time >> POI[i * 2 + 1].time;
    POI[i * 2].start = true, POI[i * 2 + 1].start = false;
    POI[i * 2].intervalNum = POI[i * 2 + 1].intervalNum = i;
  }

  sort(POI.begin(), POI.begin() + N * 2, [](const auto& a, const auto& b)
  {
    if (a.time == b.time) return a.start;
    return a.time < b.time;
  });

  // 2 cases:
  // a) One cow is in the same interval as another cow, so that cow can
  //    be removed and the least possible loss is 0 time. TODO help
  // b) No cows are in the same interval, so the least possible loss is
  //    the minimum time there is only 1 cow working.

  int currCows = 0;
  ll minTime = 1000000020, totalTime = 0, lastZero = 0;
  unordered_set<int> starts;
  for (int i = 0; i < N * 2; ++i)
  {
    if (currCows == 0) lastZero = i;

    // going up from >= 1 *not* 0
    if (currCows >= 1 && POI[i].start)
      starts.insert(POI[i].intervalNum);

    if (!POI[i].start && starts.find(POI[i].intervalNum) != starts.end() && currCows > 1)
      minTime = 0;

    if (!POI[i].start && starts.size() > 0)
      starts.erase(*starts.begin());

    // going up to 2 or down to 0 means we are ending an interval of only 1 cow,
    // so update the minTime
    if (currCows == 1)
    {
      minTime = min(minTime, POI[i].time - POI[i - 1].time);

      // if going down to 0, update total time
      if (!POI[i].start)
        totalTime += POI[i].time - POI[lastZero].time;
    }

    currCows += (POI[i].start ? 1 : -1);
  }

  fout << totalTime - minTime << '\n';

  return 0;
}
