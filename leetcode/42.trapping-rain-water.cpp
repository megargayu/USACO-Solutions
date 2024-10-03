#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution
{
public:
  int trap(vector<int> &height)
  {
    if (height.size() == 1)
      return 0;

    const int n = height.size();

    // prevent backtracking by keeping track of highest value from right
    vector<int> highest(n + 1);
    for (int i = n - 1; i >= 0; i--)
      highest[i] = max(height[i], highest[i + 1]);

    int ans = 0;

    // greedy 2 pointers
    for (int i = 0, j = 1; i < n && j < n;)
    {
      // we are near end or just started, there is no border here
      if (height[i] == 0)
      {
        i++, j++;
        continue;
      }

      int subtract = 0;
      for (; j < n && (height[j] < height[i] && height[j] < highest[i + 1]); j++)
        subtract += height[j];

      ans += min(height[i], height[j]) * (j - i - 1) - subtract;

      i = j;
      j++;
    }

    return ans;
  }
};
// @lc code=end

int main()
{
  vector<int> height = {2,1,0,2};
  Solution sol;
  cout << sol.trap(height) << '\n';
}
