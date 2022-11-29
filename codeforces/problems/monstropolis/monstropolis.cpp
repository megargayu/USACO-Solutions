// https://codeforces.com/contest/733/problem/C

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 500
#define pib pair<int, bool>

int n, k;
int bi;
int lastProc;
bool impossible = false;
vector<int> a(MAX_N), b(MAX_N);
vector<pib> instr;

bool check(int i)
{
  int l = i, r = i;
  int currSum = a[i];
  int monsterI = i - (lastProc + 1) + bi;
  vector<pib> currInstr;
  
  while (currSum < b[bi])
  {
    if (l > 0 && currSum > a[l - 1] && l > lastProc + 1)
    {
      --l;

      currSum += a[l];
      currInstr.push_back({monsterI, true});
      --monsterI;
    }
    else if (r < n - 1 && currSum > a[r + 1])
    {
      ++r;

      currSum += a[r];
      currInstr.push_back({monsterI, false});
    }
    else
      break;
  }

  if (currSum != b[bi])
    return false;

  // if they are equal but it doesn't use the monster after the last "component"
  // then that monster will be in the final queue, meaning this is impossible!
  if (l != lastProc + 1)
  {
    impossible = true;
    return false;
  }

  lastProc = r;
  instr.insert(instr.end(), currInstr.begin(), currInstr.end());
  return true;
}

int main()
{
  cin >> n;

  for (int i = 0; i < n; ++i)
    cin >> a[i];

  cin >> k;

  for (int i = 0; i < k; ++i)
    cin >> b[i];

  if (accumulate(a.begin(), a.begin() + n, 0) != accumulate(b.begin(), b.begin() + k, 0))
  {
    cout << "NO\n";
    return 0;
  }

  lastProc = -1;
  bi = 0;
  int i;
  for (i = 0; i < n; ++i)
  {
    bool checked = check(i);
    
    if (impossible)
      break;

    if (checked)
    {
      ++bi;
      i = lastProc;
    }
  }

  if (impossible || bi < k)
    cout << "NO\n";
  else
  {
    cout << "YES\n";
    for (int i = 0; i < instr.size(); ++i)
      cout << instr[i].first + 1 << ' ' << (instr[i].second ? "L" : "R") << '\n';
  }

  return 0;
}
