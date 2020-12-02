#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
  ifstream f("input.txt");
  vector<int> xx;
  for (string line; getline(f, line);)
  {
    xx.push_back(stoi(line));
  }

  //part 1
  for (int i = 0; i < xx.size(); i++)
  {
    int x = xx[i];
    for (int j = i; j < xx.size(); j++)
    {
      int y = xx[j];
      if (x + y == 2020)
        cout << x * y << endl;
    }
  }

  // part2
  for (int i = 0; i < xx.size(); i++)
  {
    int x = xx[i];
    for (int j = i; j < xx.size(); j++)
    {
      int y = xx[j];
      for (int k = j; k < xx.size(); k++)
      {
        int z = xx[k];

        if (x + y + z == 2020)
          cout << x * y * z << endl;
      }
    }
  }

  return 0;
}