#include <iostream>
#include <string>
#include <vector>
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
  string file = "";
  int i = 0;
  xx.push_back("");
  while (getline(f, foo))
  {
    file = file + foo + "\n";
  }

  regex rgx("abc");
  smatch matches;

  if (regex_search(file, matches, rgx))
  {
    std::cout << "Match found\n";

    for (size_t i = 0; i < matches.size(); ++i)
    {
      std::cout << i << ": '" << matches[i].str() << "'\n";
    }
  }
  else
  {
    std::cout << "Match not found\n";
  }

  // cout << file;

  //part 1
  int ct = 0;

  cout << ct << endl;

  return 0;
}