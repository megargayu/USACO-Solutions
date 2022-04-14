#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define MAX_N 2500
#define INF 2e9
#define ll long long
#define sc static_cast

using ordered_set = tree<
                    int,
                    null_type,
                    less<>,
                    rb_tree_tag,
                    tree_order_statistics_node_update>;

vector<pair<ll, ll>> pairs(MAX_N);
int main()
{
  int N;
  cin >> N;

  ll ans = N + 1;
  for (int i = 0; i < N; ++i)
    cin >> pairs[i].first >> pairs[i].second;
  
  sort(pairs.begin(), pairs.begin() + N);

  for (int i = 0; i < N - 1; ++i)
  {
    ordered_set set;
    set.insert(pairs[i].second);
    for (int j = i + 1; j < N; ++j)
    {
      ll lowest = min(pairs[i].second, pairs[j].second), 
         highest = max(pairs[i].second, pairs[j].second);
      set.insert(pairs[j].second);
      
      ll x = sc<ll>(set.order_of_key(lowest)),
         y = sc<ll>(set.order_of_key(INF)) - sc<ll>(set.order_of_key(highest)) - 1;

      ans += x + y + x*y + 1;
    }
  }

  cout << ans << '\n';
  return 0;
}
