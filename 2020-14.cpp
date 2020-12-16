#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <regex>
#include <set>
#include <bitset>
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

  // string maskor = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
  // string maskand = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
  // map<uint64_t, uint64_t> m;
  // for (size_t i = 0; i < xx.size(); i++)
  // {
  //   string x = xx[i];
  //   if (x.substr(0, 4) == "mask")
  //   {
  //     maskor = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
  //     maskand = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
  //     // cout << "mask " << x << endl;
  //     for (size_t j = 7; j < x.size(); j++)
  //     {
  //       if (x[j] == 'X')
  //       {
  //         maskor[j - 7] = '0';
  //         maskand[j - 7] = '1';
  //       }
  //       else if (x[j] == '1')
  //       {
  //         maskor[j - 7] = '1';
  //         maskand[j - 7] = '1';
  //       }
  //       else if (x[j] == '0')
  //       {
  //         maskor[j - 7] = '0';
  //         maskand[j - 7] = '0';
  //       }
  //     }
  //   }
  //   else
  //   {
  //     int pos = x.find(']');
  //     int addr = stoi(x.substr(4, pos - 4));
  //     uint64_t val = stoll(x.substr(pos + 4));
  //     uint64_t n = stoll(maskor, nullptr, 2) | (val & stoll(maskand, nullptr, 2));
  //     m[addr] = n;
  //   }
  // }

  // uint64_t a = 0;
  // for (auto i = m.begin(); i != m.end(); i++)
  // {
  //   a += (*i).second;
  // }

  // cout << a << endl;

  // part 2
  vector<string> masksand;
  vector<string> masksor;

  map<uint64_t, uint64_t> m;
  for (size_t i = 0; i < xx.size(); i++)
  {
    string x = xx[i];
    if (x.substr(0, 4) == "mask")
    {
      masksor.clear();
      masksand.clear();
      masksor.push_back("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
      masksand.push_back("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
      // cout << "mask " << x << endl;
      for (size_t j = 7; j < x.size(); j++)
      {
        if (x[j] == 'X')
        {
          // cout << "x" << endl;
          int size = masksor.size();
          for (size_t k = 0; k < size; k++)
          {
            masksor.push_back(masksor[k]);
            masksor[masksor.size() - 1][j - 7] = '1';
            masksor[k][j - 7] = '0';
            masksand.push_back(masksand[k]);
            masksand[masksand.size() - 1][j - 7] = '1';
            masksand[k][j - 7] = '0';
          }
        }
        else if (x[j] == '1')
        {
          // cout << "1" << endl;
          for (size_t k = 0; k < masksor.size(); k++)
          {
            masksor[k][j - 7] = '1';
            masksand[k][j - 7] = '1';
          }
        }
        else if (x[j] == '0')
        {
          // cout << "0" << endl;
          for (size_t k = 0; k < masksor.size(); k++)
          {
            masksor[k][j - 7] = '0';
            masksand[k][j - 7] = '1';
          }
        }
      }
    }
    else
    {
      // cout << "not mask" << endl;
      int pos = x.find(']');
      int addr = stoi(x.substr(4, pos - 4));
      uint64_t val = stoll(x.substr(pos + 4));
      for (size_t j = 0; j < masksor.size(); j++)
      {
        //   cout << j << "val " << bitset<36>(val) << endl;
        //   cout << j << "and " << bitset<36>(val) << endl;
        //   cout << j << "or  " << bitset<36>(val) << endl;

        uint64_t a = stoll(masksor[j], nullptr, 2) | (addr & stoll(masksand[j], nullptr, 2));
        m[a] = val;
      }
    }
  }

  uint64_t a = 0;
  for (auto i = m.begin(); i != m.end(); i++)
  {
    a += (*i).second;
  }
  cout << a << endl;
  return 0;
}
