// https://open.kattis.com/contests/acpc17open/problems/laneswitching
// https://www.desmos.com/calculator/rczjgoy8if

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100

// can represent a gap or a car
struct Rect
{
  int l, d;
  int i; // unique index
};

struct Edge
{
  int s; // safety factor
  int to;
};

// NOTE: There are at most 100 cars in each lane.
Rect acm;
vector<vector<Rect>> cars(MAX_N), gaps(MAX_N);

// 1e5 is very considerate, should never be more than that
vector<vector<Edge>> adj(1e5);
vector<int> dist(1e5, -1);

int findGap(int d, int n)
{
  int lo = 0, hi = cars[n].size() - 1, mid, ans = -1;
  while (lo <= hi)
  {
    mid = lo + (hi - lo) / 2;
    if (gaps[n][mid].d + gaps[n][mid].l > d)
    {
      ans = mid;
      hi = mid - 1;
    }
    else
      lo = mid + 1;
  }

  return ans;
}

int main()
{
  int N, M, R;
  cin >> N >> M >> R;
  R *= 2; // double all values so we don't have to deal with decimals

  // 0. input
  int n, l, d;

  cin >> n >> acm.l >> acm.d; // ignore n as it is always 0 for acm
  acm.l *= 2;
  acm.d *= 2;
  for (int i = 1; i < M; ++i)
  {
    cin >> n >> l >> d;
    l *= 2, d *= 2;
    cars[n].push_back({l, d});
  }

  for (int i = 0; i < N; ++i)
  {
    sort(cars[i].begin(), cars[i].end(), [](const auto &a, const auto &b)
         { return a.d < b.d; });
    // insert dummy cars to indicate beginning and end of lane
    cars[i].insert(cars[i].begin(), {0, 0});
    cars[i].push_back({0, R});
  }

  // 1. calculate gaps
  int gapI = 0;
  for (int n = 0; n < N; ++n)
  {
    // gaps between this car and the next
    for (int i = 0; i < cars[n].size() - 1; ++i)
    {
      const int carEnd = cars[n][i].d + cars[n][i].l;
      gaps[n].push_back({cars[n][i + 1].d - carEnd, carEnd, gapI});
      ++gapI;
    }
  }

  const int numGaps = gaps[N - 1][gaps[N - 1].size() - 1].i;
  assert(numGaps < 1e5);

  // 2. create a graph connecting gaps next to each other
  // (go left to right once only to avoid double counting)
  int acmIn = -1; // which gap is the ACM car in?
  for (int n = 0; n < N - 1; ++n)
  {
    for (int i = 0; i < gaps[n].size(); ++i)
    {
      const auto &a = gaps[n][i];
      // find first gap j where d[j] + l[j] >= d[i] using binary search
      int gap = findGap(a.d, n + 1);

      if (n == 0 && acm.d >= a.d && acm.d + acm.l <= a.d + a.l)
      {
        assert(acmIn == -1);
        acmIn = a.i;
      }

      for (; gap < gaps[n + 1].size() && gaps[n + 1][gap].d < gaps[n][i].d + gaps[n][i].l; ++gap)
      {
        // gaps gaps[n][i] and gaps[n + 1][gap] are connected! add to graph
        const auto &b = gaps[n + 1][gap];
        const int gapSize = min(a.d + a.l, b.d + b.l) - max(a.d, b.d);
        if (gapSize >= acm.l) // make sure the car can fit in this gap
        {
          // maximum safety factor while going between gap a and b (after dividing, this value is still doubled!!)
          const int s = (gapSize - acm.l) / 2;
          adj[a.i].push_back({s, b.i});
          adj[b.i].push_back({s, a.i});
        }
      }
    }
  }

  assert(acmIn != -1);
  const auto &acmGap = gaps[0][acmIn];

  // 3. run dijkstra's algorithm to find the path with the maximum safety factor
  auto cmp = [](const Edge &a, const Edge &b)
  { return a.s < b.s; };
  priority_queue<Edge, vector<Edge>, decltype(cmp)> q(cmp);

  // when the acm car starts, it has an intial safety factor
  const int initialS = min(acm.d - acmGap.d, (acmGap.d + acmGap.l) - (acm.d + acm.l));
  dist[acmIn] = initialS;
  q.push({initialS, acmIn});

  while (!q.empty())
  {
    int v = q.top().to;
    q.pop();

    for (const Edge &e : adj[v])
    {
      if (dist[e.to] < min(dist[v], e.s))
      {
        dist[e.to] = min(dist[v], e.s);
        q.push({dist[e.to], e.to});
      }
    }
  }

  int ans = -1;
  for (const auto &g : gaps[N - 1])
    ans = max(ans, dist[g.i]);
  
  if (ans == -1)
  {
    cout << "Impossible\n";
    return 0;
  }

  cout << ans / 2 << '.' << (ans % 2 == 0 ? '0' : '5') << "00000\n";

  return 0;
}
