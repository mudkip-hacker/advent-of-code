#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <regex>
#include <set>
#include <unordered_map>
using namespace std;

int main()
{
  ifstream f("input.txt");

  string xx;
  getline(f, xx);

  vector<int> x;
  vector<int> y;
  size_t pos = 0;
  string t;
  while ((pos = xx.find(',')) != string::npos)
  {
    string f = xx.substr(0, pos);
    x.push_back(stoi(f));
    y.push_back(stoi(f));
    // cout << " hi " << x[x.size() - 1];
    xx.erase(0, pos + 1);
  }
  // cout << " hi " << xx;
  x.push_back(stoi(xx));
  y.push_back(stoi(xx));
  int i = x.size() - 1;
  int n = 2020;
  for (; i <= n;)
  {
    i = x.size() - 1;
    for (int j = x.size() - 2; j >= 0; j--)
    {
      // cout << "comp " << x[j] << " " << x[i] << " " << i << " " << j << endl;
      if (x[j] == x[i])
      {
        x.push_back(i - j);
        // cout << "new " << i - j << endl;
        break;
      }
      else if (j == 0)
      {
        x.push_back(0);
      }
    }
  }

  cout << "asd " << x[n - 1] << endl;

  map<int, vector<int>> m;
  vector<int> v;
  int ct = 30000000;
  int last = y[y.size() - 1];
  for (size_t i = 0; i < y.size(); i++)
  {
    v.push_back(y[i]);
    m[y[i]].push_back(i + 1);
  }
  i = y.size();
  while (i <= ct)
  {
    if (i % 100000 == 0)
    {
      cout << "time " << i << endl;
    }
    auto x = v[i - 1];
    // cout << "hi " << x << " " << (m[x])[m[x].size() - 1] << " " << i << endl;
    if ((m[x])[m[x].size() - 1] == i)
    {
      v.push_back(0);
      if (m.find(0) == m.end())
      {
        // cout << "new " << next << " " << i + 1 << endl;
        m[0] = {1 + i};
      }
    }
    else
    {
      int next = i - m[x][m[x].size() - 1];
      // cout << "find " << next << endl;
      if (m.find(next) == m.end())
      {
        // cout << "new " << next << " " << i + 1 << endl;
        m[next] = {1 + i};
      }
      m[x].push_back(i);
      v.push_back(next);
    }
    // for (size_t j = 0; j < v.size(); j++)
    // {
    //   cout << v[j] << " ";
    // }
    // cout << endl;

    i++;
  }
  cout << v[ct - 1] << endl;

  // 3

  return 0;
}
