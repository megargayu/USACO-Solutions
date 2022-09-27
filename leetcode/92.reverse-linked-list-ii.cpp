struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
using namespace std;
#include <bits/stdc++.h>

/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
  ListNode *reverseBetween(ListNode *head, int left, int right)
  {
    // find left
    ListNode *curr = head;
    ListNode *last{};
    ListNode *beforeHead{};
    ListNode *afterHead{};
    int i = 0;
    do
    {
      // if (curr->val == left) beforeHead = last;
      if (curr->val == right)
        afterHead = curr->next;

      ++i;
      last = curr;
      curr = curr->next;
    } while (curr != nullptr);

    cout << (beforeHead == nullptr) << '\n';

    return head;
  }
};
// @lc code=end

int main()
{
  Solution sol;
  ListNode five(5);
  ListNode four(4, &five);
  ListNode three(3, &four);
  ListNode two(2, &three);
  ListNode head(1, &two);
  sol.reverseBetween(&head, 2, 4);
}
