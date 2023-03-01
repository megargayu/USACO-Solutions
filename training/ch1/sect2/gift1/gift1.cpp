/*
TASK: gift1
ID: megarga1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
  ifstream fin("gift1.in");
  ofstream fout("gift1.out");

  int NP;
  fin >> NP;

  vector<string> nameOrder(NP);
  map<string, int> accounts;
  for (int i{0}; i < NP; ++i)
  {
    string name;
    fin >> name;
    accounts[name] = 0;
    nameOrder[i] = name;
  }

  for (int i{0}; i < NP; ++i)
  {
    string giving;
    fin >> giving;

    int amount, num;
    fin >> amount >> num;

    if (num == 0)
      continue;

    accounts[giving] = accounts[giving] - amount + amount % num;

    int giveToEach{amount / num};
    for (int j{0}; j < num; ++j)
    {
      string givingTo;
      fin >> givingTo;
      accounts[givingTo] += giveToEach;
    }
  }

  for (string name : nameOrder)
  {
    fout << name << ' ' << accounts[name] << '\n';
  }

  return 0;
}