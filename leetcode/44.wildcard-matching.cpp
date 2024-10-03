#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
class Solution {
struct State
{
  int si, pi;
};

public:
    array<array<bool, 2004>, 2004> vis;

    bool isMatch(string s, string p) {
        // edge case
        if (s == "")
        {
          for (char c : p)
            if (c != '*')
              return false;
          
          return true;
        }

        queue<State> q;
        q.push(State{0, 0});

        while (!q.empty())
        {
          auto [si, pi] = q.front();
          q.pop();

          if (vis[si][pi]) continue;
          vis[si][pi] = true;

          if (si == s.length() && pi == p.length())
            return true;
          else if (si > s.length() || pi == p.length())
            continue;

          switch (p[pi])
          {
          case '*':
            // Either fully consume right now or don't
            q.push(State{si+1, pi+1});
            q.push(State{si+1, pi});
            q.push(State{si, pi+1});
            break;

          case '?':
            q.push(State{si+1, pi+1});
            break;

          default:
            if (si < s.length() && p[pi] == s[si])
              q.push(State{si+1, pi+1});
            break;
          }
        }

        return false;
    }
};
// @lc code=end

int main()
{
  string s = "acdcb";
  string p = "a*c?b";

  Solution sol;
  cout << (sol.isMatch(s, p) ? "true" : "false") << '\n';
}

