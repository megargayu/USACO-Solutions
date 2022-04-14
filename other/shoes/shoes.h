// FOR TESTING
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int sum(int v, int tl, int tr, int l, int r);
void update(int v, int tl, int tr, int pos, int new_val);
ll count_swaps(vector<int> S);

int main()
{
  cout << count_swaps({ -2, 2, 2, -2, -2, 2 }) << '\n';
  cout << sum(1, 0, 5, 0, 5) << '\n';
}
