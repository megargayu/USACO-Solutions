#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
      if (nums.size() == 1) return nums[0];
      if (nums.size() == 2) return max(nums[0], nums[1]);

      int n3 = nums[0], n2 = nums[1], 
        n1 = n3 + nums[2], curr;

      for (int i = 3; i < nums.size(); ++i)
      {
        curr = max(n2, n3) + nums[i];
        n3 = n2;
        n2 = n1;
        n1 = curr;
      }

      return max(n2, n1);
    }
};
// @lc code=end


int main()
{
  Solution sol;
  vector<int> nums{1, 2, 3, 1};
  cout << sol.rob(nums) << '\n';
  return 0;
}
