#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <regex>
#include <set>
using namespace std;

int main()
{
  ifstream f("input.txt");
  vector<string> xx;
  string foo;
  while (getline(f, foo))
  {
    xx.push_back(foo);
  }

  ifstream f2("input2.txt");
  vector<string> xx2;
  while (getline(f2, foo))
  {
    xx2.push_back(foo);
  }

  regex rgx("^([\\w\\s]+): (\\d+)-(\\d+) or (\\d+)-(\\d+)$");
  smatch matches;
  vector<string> field;
  set<int> valid;
  vector<set<int>> sett;
  for (size_t j = 0; j < xx.size(); j++)
  {
    set<int> foo;

    string s = xx[j];
    regex_search(s, matches, rgx);
    for (size_t j = 0; j < matches.size(); j++)
    {
      cout << j << " " << matches[j] << endl;
    }

    field.push_back(matches[1]);
    for (size_t i = stoi(matches[2]); i <= stoi(matches[3]); i++)
    {
      valid.insert(i);
      foo.insert(i);
    }
    for (size_t i = stoi(matches[4]); i <= stoi(matches[5]); i++)
    {
      valid.insert(i);
      foo.insert(i);
    }
    sett.push_back(foo);
  }

  vector<vector<int>> y;
  for (size_t i = 0; i < xx2.size(); i++)
  {
    cout << xx2[i] << endl;
    size_t pos = 0;
    y.push_back({});
    while ((pos = xx2[i].find(',')) != string::npos)
    {
      string f = xx2[i].substr(0, pos);
      y[i].push_back(stoi(f));
      xx2[i].erase(0, pos + 1);
    }
    y[i].push_back(stoi(xx2[i]));
  }

  int ct = 0;
  cout << "before cut " << y.size() << endl;
  for (size_t i = 0; i < y.size(); i++)
  {
    cout << "erase loop " << i << endl;
    bool val = true;
    for (size_t j = 0; j < y[i].size(); j++)
    {
      // cout << "comp " << y[i][j] << " " << valid.size() << endl;
      if (valid.find(y[i][j]) == valid.end())
      {
        cout << "no " << y[i][j] << endl;
        val = false;
        ct += y[i][j];
        break;
      }
    }
    if (!val)
    {
      y.erase(y.begin() + i);
      i--;
    }
  }
  cout << "after cut " << y.size() << endl;
  cout << ct << endl;

  map<string, int> field2ind;

  set<int> included;
  for (size_t i = 0; i < field.size(); i++)
  {
    set<int> valids = sett[i];
    for (size_t j = 0; j < y[0].size(); j++)
    {
      bool match = true;
      if (included.find(j) != included.end())
      {
        continue;
      }
      for (size_t k = 0; k < y.size(); k++)
      {
        if (valids.find(y[k][j]) == valids.end())
        {
          match = false;
          break;
        }
      }
      if (match)
      {
        cout << "field " << field[i] << " j " << j << endl;
        field2ind[field[i]] = j;
        included.insert(j);
        for (auto l = included.begin(); l != included.end(); l++)
        {
          cout << (*l) << " ";
        }
        cout << endl;

        break;
      }
    }
  }

  for (auto i = field2ind.begin(); i != field2ind.end(); i++)
  {
    cout << "field " << (*i).first << " " << (*i).second << endl;
  }
  //267593065651

  return 0;
}
