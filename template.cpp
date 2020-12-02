#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
  // read list of ints
  // ifstream f("input.txt");
  // vector<int> xx;
  // for (string line; getline(f, line);)
  // {
  //   xx.push_back(stoi(line));
  // }

  // read list of int-int char: string
  ifstream f("input.txt");
  vector<int> xx;
  vector<int> yy;
  vector<string> cc;
  vector<string> ss;
  for (string line; getline(f, line);)
  {
    size_t i = line.find('-');
    xx.push_back(stoi(line.substr(0, i)));
    size_t j = line.find(' ');
    yy.push_back(stoi(line.substr(i + 1, j - i)));
    size_t k = line.substr(i + 1).find(' ');
    cc.push_back(line.substr(j + 1, k - j - 1));
    ss.push_back(line.substr(j + 4));
    // printf("%d %d %s %s", xx[0], yy[0], cc[0].c_str(), ss[0].c_str());
  }

  //loop
  for (auto &x : xx)
  {
  }

  //loop
  for (int i = 0; i < xx.size(); i++)
  {
    int x = xx[i];
  }

  // triple loop through
  for (int i = 0; i < xx.size(); i++)
  {
    int x = xx[i];
    for (int j = i; j < xx.size(); j++)
    {
      int y = xx[j];
      for (int k = j; k < xx.size(); k++)
      {
        int z = xx[k];
      }
    }
  }

  return 0;
}