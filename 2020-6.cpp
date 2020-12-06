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

    vector<pair<string, int>> xx;
    string line;
    int i = 0;
    xx.push_back(pair<string, int>("", 0));
    while (getline(f, line))
    {
        if (line == "")
        {
            i++;
            xx.push_back(pair<string, int>("", 0));
            continue;
        }
        xx[i].first = xx[i].first + line;
        xx[i].second++;
    }

    //part 1
    int ct = 0;
    for (size_t i = 0; i < xx.size(); i++)
    {
        string x = xx[i].first;
        set<char> s;
        for (size_t j = 0; j < x.size(); j++)
        {
            s.insert(x[j]);
        }
        ct += s.size();
    }
    cout << ct << endl;

    //part 2
    ct = 0;
    for (size_t i = 0; i < xx.size(); i++)
    {
        int need = xx[i].second;
        string x = xx[i].first;
        vector<int> s;
        for (size_t j = 0; j < 26; j++)
        {
            s.push_back(count(x.begin(), x.end(), j + 'a'));
        }
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == need)
                ct++;
        }
    }
    cout << ct << endl;

    return 0;
}