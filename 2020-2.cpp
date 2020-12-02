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
    size_t k = line.substr(j + 1).find(' ') + j + 1;
    cc.push_back(line.substr(j + 1, 1));
    ss.push_back(line.substr(k + 1));
    // printf("%d %d %d, %d %d %s %s", i, j, k, xx[0], yy[0], cc[0].c_str(), ss[0].c_str());
  }

  // part 1
  int count = 0;
  for (int i = 0; i < xx.size(); i++)
  {
    int x = xx[i];
    int y = yy[i];
    string c = cc[i];
    string s = ss[i];
    int asd = 0;
    // printf(" %d %d %s %s\n", x, y, c.c_str(), s.c_str());
    for (size_t j = 0; j < s.size(); j++)
    {
      string q = s.substr(j, 1);
      // printf("comp %s with %s \n", q.c_str(), c.c_str());
      if (q == c)
      {
        asd++;
      }
    }
    if (asd >= x && asd <= y)
      count++;
  }
  cout << count << endl;

  // part 2
  count = 0;
  for (int i = 0; i < xx.size(); i++)
  {
    int x = xx[i];
    int y = yy[i];
    string c = cc[i];
    string s = ss[i];
    printf("%d %d %d %s %s val %d x%d y%d\n", s[x - 1] == c[0], s[y - 1] == c[0], s[x - 1] != s[y - 1], s.c_str(), c.c_str(), (s[x - 1] == c[0] || s[y - 1] == c[0]) && s[x - 1] != s[y - 1], x, y);
    if ((s[x - 1] == c[0] || s[y - 1] == c[0]) && s[x - 1] != s[y - 1])
      count++;
    // 407
  }
  cout << count << endl;
  return 0;
}